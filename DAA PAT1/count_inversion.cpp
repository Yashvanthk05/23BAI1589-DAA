#include<iostream>
#include<vector>
#include<map>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high,int &count){
  vector<int> l(arr.begin()+low,arr.begin()+mid+1),r(arr.begin()+mid+1,arr.begin()+high+1);
  int i=0,j=0,k=low;
  while(i<l.size() && j<r.size()){
    if(l[i]<=r[j]) arr[k++]=l[i++];
    else{
      arr[k++]=r[j++];
      count+=(l.size()-i);
    }
  }
  while(i<l.size()) arr[k++]=l[i++];
  while(j<r.size()) arr[k++]=r[j++];
}

void mergeSort(vector<int> &arr,int low,int high,int &count){
  if(low>=high) return;
  int mid=(low+high)/2;
  mergeSort(arr,low,mid,count);
  mergeSort(arr,mid+1,high,count);
  merge(arr,low,mid,high,count);
}

int main(){
  vector<int> pre={5,4,3,2,1};
  vector<int> fin={4,5,1,3,2};
  vector<int> arr;
  map<int,int> mpp;
  for(int i=0;i<pre.size();i++) mpp[pre[i]]=i+1;
  for(int i=0;i<fin.size();i++) arr.push_back(mpp[fin[i]]);
  int count=0;
  mergeSort(arr,0,arr.size()-1,count);
  cout<<count<<endl;
  return 0;
}