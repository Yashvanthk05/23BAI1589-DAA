#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high){
  vector<int> l(arr.begin()+low,arr.begin()+mid+1),r(arr.begin()+mid+1,arr.begin()+high+1);
  int i=0,j=0,k=low;
  while(i<l.size() && j<r.size()){
    if(l[i]>=r[j]) arr[k++]=l[i++];
    else arr[k++]=r[j++];
  }
  while(i<l.size()) arr[k++]=l[i++];
  while(j<r.size()) arr[k++]=r[j++];
}

void mergeSort(vector<int> &arr,int low,int high){
  if(low>=high) return;
  int mid=(low+high)/2;
  mergeSort(arr,low,mid);
  mergeSort(arr,mid+1,high);
  merge(arr,low,mid,high);
}

void FiboDesc(vector<int> &arr,int n){
  vector<int> fibseq={1,2};
  while((fibseq[fibseq.size()-2]+fibseq[fibseq.size()-1])<n){
    fibseq.push_back(fibseq[fibseq.size()-2]+fibseq[fibseq.size()-1]);
  }
  vector<int> res;
  for(int i:fibseq){
    res.push_back(arr[i]);
  }
  mergeSort(res,0,res.size()-1);
  for(int i=0;i<res.size();i++){
    arr[fibseq[i]]=res[i];
  }
}

int maxDigit(int num){
  if(num>=0 && num<=9) return num;
  int left=maxDigit(num/(int)pow(10,(int)(log10(num)/2)));
  int right=maxDigit(num%(int)pow(10,(int)(log10(num)/2)));
  return max(left,right);
}

void printarr(vector<int> arr,int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main(){
  // vector<int> arr={1,2,3,4,5,6,7,8,9,10};
  // int n=arr.size();
  // printarr(arr,n);
  // FiboDesc(arr,n);
  // printarr(arr,n);
  cout<<maxDigit(2328673)<<endl;
  return 0;
}