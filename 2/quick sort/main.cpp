#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<filesystem>
#include<ctime>
#include<cstdlib>
using namespace std;

class Data{
  public:
  int empid,salary;
  string name,department;
};

string OUTPUT_DIR="../dataset/";

int partition(vector<Data> &arr,int low,int high){
  int n=(high-low+1);
  int i=low,j=high;
  Data pivot=arr[low];
  Data temp;
  while(i<j){
    while(arr[i].empid<=pivot.empid && i<=high) i++;
    while(arr[j].empid>pivot.empid && j>=low) j--;
    if(i<j){
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[low],arr[j]);
  return j;
}

void quick_sort(vector<Data> &arr,int low,int high){
  if(low>=high) return;
  int p=partition(arr,low,high);
  quick_sort(arr,low,p-1);
  quick_sort(arr,p+1,high);
}

void sorting(string filename){
  vector<Data> arr;
  ifstream f1(filename);
  if(!f1.is_open()){
    cerr<<"Failed to open input file"<<endl;
    return;
  }
  string line;
  getline(f1,line);
  Data obj;
  while(getline(f1,line)){
    stringstream ss(line);
    string empid_str, salary_str;
    getline(ss, empid_str, ',');
    getline(ss, obj.name, ',');
    getline(ss, obj.department, ',');
    getline(ss, salary_str, ',');
    obj.empid = stoi(empid_str);
    obj.salary = stoi(salary_str);
    arr.push_back(obj);
  }
  f1.close();
  clock_t start=clock();
  quick_sort(arr,0,arr.size()-1);
  clock_t end=clock();
  cout<<filename<<" Time Taken: "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<<endl;
  filesystem::create_directories("output");
  ofstream f2("output/"+filesystem::path(filename).filename().string());
  f2<<"EmployeeID,Name,Department,Salary"<<endl;
  for(int i=0;i<arr.size();i++){
    string str=to_string(arr[i].empid)+","+arr[i].name+","+arr[i].department+","+to_string(arr[i].salary);
    f2<<str<<endl;
  }
  f2.close();
}

int main(int argc,char* argv[]){
  if(argc!=2){
    cerr<<"Input Filename"<<endl;
    return 1;
  }
  cout<<"Quick Sort:"<<endl;
  sorting(argv[1]);
  return 0;
}