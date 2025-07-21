#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

int partition(vector<int> &arr,int low,int high){
  int pivot=arr[low];
  int i=low,j=high;
  while(i<j){
    while(arr[i]<=pivot && i<=high) i++;
    while(arr[j]>pivot && j>=low) j--;
    if(i<j) swap(arr[i],arr[j]);
  }
  swap(arr[low],arr[j]);
  return j;
}

void quickSort(vector<int> &arr,int low,int high){
  if(low>=high) return;
  int p=partition(arr,low,high);
  quickSort(arr,low,p-1);
  quickSort(arr,p+1,high);
}

int main(){
  vector<int> arr;
  ifstream f1("stud_height3.txt");
  int num;
  if(f1.is_open()){
    while(f1>>num) arr.push_back(num);
    f1.close();
  }
  int n=arr.size();
  clock_t start=clock();
  quickSort(arr,0,n-1);
  clock_t end=clock();
  cout<<"Quick Sort Time Taken (30000 values): "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
  ofstream f2("out_stud_height3.txt");
  for(int i=0;i<n;i++){
    f2<<arr[i]<<endl;
  }
  return 0;
}


