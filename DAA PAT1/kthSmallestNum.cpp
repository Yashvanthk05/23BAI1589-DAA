#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int low,int high){
  int i=low,j=high;
  int pivot=arr[low];
  while(i<j){
    while(i<=high && arr[i]<=pivot) i++;
    while(j>=low && arr[j]>pivot) j--;
    if(i<j) swap(arr[i],arr[j]);
  }
  swap(arr[low],arr[j]);
  return j;
}

int quickSort(vector<int> &arr,int low,int high,int k){
  if(low>high) return -1;
  int p=partition(arr,low,high);
  if(p==k-1) return arr[p];
  else if(p>k-1) return quickSort(arr,low,p-1,k);
  return quickSort(arr,p+1,high,k);
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int k;
  cin>>k;
  cout<<quickSort(arr,0,n-1,k);
}