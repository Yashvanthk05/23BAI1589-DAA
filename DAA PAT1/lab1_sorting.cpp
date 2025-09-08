#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void insertion_sort(vector<int> &arr,int n){
  cout<<"Insertion Sort: "<<endl;
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

void selection_sort(vector<int> &arr,int n){
  cout<<"Selection Sort: "<<endl;
  for(int i=0;i<n-1;i++){
    int minidx=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[minidx]) minidx=j;
    }
    swap(arr[i],arr[minidx]);
  }
}

void printarr(vector<int> arr,int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void merge(vector<int> &arr,int low,int mid,int high){
  vector<int> left(arr.begin()+low,arr.begin()+mid+1),right(arr.begin()+mid+1,arr.begin()+high+1);
  int i=0,j=0,k=low;
  while(i<left.size() && j<right.size()){
    if(left[i]<=right[j]) arr[k++]=left[i++];
    else arr[k++]=right[j++];
  }
  while(i<left.size()) arr[k++]=left[i++];
  while(j<right.size()) arr[k++]=right[j++];
}

void mergeSort(vector<int> &arr,int low,int high){
  if(low>=high) return;
  int mid=(low+high)/2;
  mergeSort(arr,low,mid);
  mergeSort(arr,mid+1,high);
  merge(arr,low,mid,high);
}

int partition(vector<int> &arr,int low,int high){
  int pivot=arr[low];
  int i=low,j=high;
  while(i<j){
    while(i<=high && arr[i]<=pivot) i++;
    while(j>=low && arr[j]>pivot) j--;
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
  vector<int> arr={5,4,3,2,1};
  int n=arr.size();
  printarr(arr,n);
  //insertion_sort(arr,n);
  //selection_sort(arr,n);
  //mergeSort(arr,0,n-1);
  //quickSort(arr,0,n-1);
  printarr(arr,n);
  return 0;
}