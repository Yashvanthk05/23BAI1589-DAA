#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

void merge(vector<int> &odd_arr,int low,int mid,int high){
  vector<int> temp;
  int i=low,j=mid+1;
  while(i<=mid && j<=high){
    if(odd_arr[i]<odd_arr[j]) temp.push_back(odd_arr[i++]);
    else temp.push_back(odd_arr[j++]);
  }
  while(i<=mid){
    temp.push_back(odd_arr[i++]);
  }
  while(j<=high){
    temp.push_back(odd_arr[j++]);
  }
  for(int i=low;i<=high;i++){
    odd_arr[i]=temp[i-low];
  }
}

void mergeSort(vector<int> &odd_arr,int low,int high){
  if(low>=high) return;
  int mid=(low+high)/2;
  mergeSort(odd_arr,low,mid);
  mergeSort(odd_arr,mid+1,high);
  merge(odd_arr,low,mid,high);
}

void sortOddIndices(vector<int> &arr,int n){
  vector<int> odd_arr;
  for(int i=0;i<n;i++){
    if((i+1)%2!=0) odd_arr.push_back(arr[i]);
  }
  mergeSort(odd_arr,0,odd_arr.size()-1);
  int idx=0;
  for(int i=0;i<odd_arr.size();i++){
    arr[idx]=odd_arr[i];
    idx+=2;
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> arr;
  int num;
  for(int i=0;i<n;i++){
    cin>>num;
    arr.push_back(num);
  }
  auto start=high_resolution_clock::now();
  sortOddIndices(arr,n);
  auto end=high_resolution_clock::now();
  for(int i=0;i<n;i++) cout<<arr[i]<<" ";
  cout<<endl;
  cout<<"Time Taken to Sort Odd Indices: "<<duration_cast<microseconds>(end-start).count()<<" microseconds"<<endl;
  return 0;
}