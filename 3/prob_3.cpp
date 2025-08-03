#include<iostream>
#include<vector>
using namespace std;

int partition(vector<double> &arr,int low,int high){
  double pivot=arr[low];
  int i=low,j=high;
  while(i<j){
    while(i<=high && pivot>=arr[i]) i++;
    while(j>=low && pivot<arr[j]) j--;
    if(i<j) swap(arr[i],arr[j]);
  }
  swap(arr[low],arr[j]);
  return j;
}

double quick_sort(vector<double> &arr,int low,int high,int k){
  if(low<=high){
    int p=partition(arr,low,high);
    if(p==k-1) return arr[p];
    else if(p>k-1) return quick_sort(arr,low,p-1,k);
    return quick_sort(arr,p+1,high,k);
  }
  return -1;
}

int main(){
  vector<double> arr;
  int n,k;
  double num;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>num;
    arr.push_back(num);
  }
  cin>>k;
  double ans=quick_sort(arr,0,n-1,k);
  cout<<k<<" Smallest Element: "<<ans<<endl;
  return 0;
}