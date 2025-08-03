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

void insertion_sort(vector<Data> &arr){
  for(int i=1;i<arr.size();i++){
    Data key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j].empid>key.empid){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
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
  insertion_sort(arr);
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
    cerr<<"Input File Name"<<endl;
    return 1;
  }
  cout<<"Insetion Sort:"<<endl;
  sorting(argv[1]);
  return 0;
}

