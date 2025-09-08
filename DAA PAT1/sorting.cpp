#include<iostream>
#include<vector>
using namespace std;

void selection_sort(vector<int> &arr,int n){
  for(int i=0;i<n-1;i++){
    int mini=i;
    for(int j=i+1;j<n;j++){
      if(arr[mini]>arr[j]) mini=j;
    }
    if(i!=mini) swap(arr[i],arr[mini]);
  }
}

void insertion_sort(vector<int> &arr,int n){
  for(int i=1;i<n;i++){
    int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
}

int partition(vector<int> &arr,int low,int high){
  int pivot=arr[low];
  int i=low,j=high;
  while(i<j){
    while(i<=high && arr[i]>=pivot) i++;
    while(j>=low && arr[j]<pivot) j++;
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
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  return 0;
}