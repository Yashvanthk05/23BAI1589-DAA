#include<iostream>
#include<vector>
using namespace std;

int maxSum(vector<int> arr,int low,int high,vector<int> &maxprofits){
  if(low==high){
    if(arr[low]>=0){
      maxprofits.push_back(arr[low]);
      return arr[low];
    }
    return 0;
  }
  int mid=(low+high)/2;
  int left=maxSum(arr,low,mid,maxprofits);
  int right=maxSum(arr,mid+1,high,maxprofits);
  return left+right;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<int> maxprofits;
  cout<<maxSum(arr,0,n-1,maxprofits)<<endl;
  for(int i=0;i<maxprofits.size();i++){
    cout<<maxprofits[i]<<" ";
  }
  cout<<endl;
  return 0;
}