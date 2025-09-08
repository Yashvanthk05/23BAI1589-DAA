#include<iostream>
#include<vector>
#include<map>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high,int *inversions){
  vector<int> left(arr.begin()+low,arr.begin()+mid+1),right(arr.begin()+mid+1,arr.begin()+high+1);
  int i=0,j=0,k=low;
  while(i<left.size() && j<right.size()){
    if(left[i]<=right[j]) arr[k++]=left[i++];
    else{
      *inversions+=left.size()-i;
      arr[k++]=right[j++];
    }
  }
  while(i<left.size()){
    arr[k++]=left[i++];
  }
  while(j<right.size()){
    arr[k++]=right[j++];
  }
}

void mergeSort(vector<int> &arr,int low,int high,int *inversions){
  if(low>=high) return;
  int mid=(low+high)/2;
  mergeSort(arr,low,mid,inversions);
  mergeSort(arr,mid+1,high,inversions);
  merge(arr,low,mid,high,inversions);
}

int main(){
  int n;
  cin>>n;
  vector<int> prerank(n),finrank(n);
  map<int,int> mpp;
  for(int i=0;i<n;i++){
    cin>>prerank[i];
    mpp[prerank[i]]=i;
  }
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>finrank[i];
    arr[i]=mpp[finrank[i]];
  }
  int inversions=0;
  mergeSort(arr,0,n-1,&inversions);
  cout<<inversions<<endl;
  return 0;
}