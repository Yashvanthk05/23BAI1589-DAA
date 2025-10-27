#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LIS(vector<int> arr,int n,vector<int> &prev,vector<int> &subs){
  int maxidx=0;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[j]<arr[i] && prev[i]<=prev[j]+1){
        prev[i]=prev[j]+1;
        subs[i]=j;
      }
    }
    if(prev[maxidx]<prev[i]) maxidx=i;
  }
  return maxidx;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<int> prev(n,1);
  vector<int> subs(n,-1);
  int idx=LIS(arr,n,prev,subs);
  vector<int> res;
  cout<<"Longest Increasing Subsequence: "<<prev[idx]<<endl;
  while(idx!=-1){
    res.push_back(arr[idx]);
    idx=subs[idx];
  }
  reverse(res.begin(),res.end());
  for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
  return 0;
}