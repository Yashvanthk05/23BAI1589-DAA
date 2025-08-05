#include<iostream>
#include<vector>
#include<map>
#include<chrono>
using namespace std::chrono;
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high,int *count){
  int i=0,j=0,k=low;
  vector<int> leftarr(arr.begin()+low,arr.begin()+mid+1);
  vector<int> rightarr(arr.begin()+mid+1,arr.begin()+high+1);
  while(i<leftarr.size() && j<rightarr.size()){
    if(leftarr[i]<=rightarr[j]) arr[k++]=leftarr[i++];
    else{
      arr[k++]=rightarr[j++];
      *count+=(leftarr.size()-i);
    }
  }
  while(i<leftarr.size()) arr[k++]=leftarr[i++];
  while(j<rightarr.size()) arr[k++]=rightarr[j++];
}

void mergeSort(vector<int> &arr,int low,int high,int *count){
  if(low==high) return;
  int mid=(low+high)/2;
  mergeSort(arr,low,mid,count);
  mergeSort(arr,mid+1,high,count);
  merge(arr,low,mid,high,count);
}

int main(){
  int n;
  cin>>n;
  vector<int> preliminaryrank(n);
  vector<int> finalrank(n);
  for(int i=0;i<n;i++){
    cin>>preliminaryrank[i];
  }
  for(int i=0;i<n;i++){
    cin>>finalrank[i];
  }
  auto start=high_resolution_clock::now();
  int count=0;
  map<int,int> mpp;
  for(int i=0;i<n;i++){
    mpp[preliminaryrank[i]]=i+1;
  }
  vector<int> finalindices(n);
  for(int i=0;i<n;i++){
    finalindices[i]=mpp[finalrank[i]];
  }
  mergeSort(finalindices,0,n-1,&count);
  auto end=high_resolution_clock::now();
  cout<<"Number of Count Inversions: "<<count<<endl;
  cout<<"Time taken: "<<duration_cast<microseconds>(end-start).count()<<" microseconds"<<endl;
  return 0;
}