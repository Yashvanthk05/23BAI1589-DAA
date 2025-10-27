#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LIS(vector<int> arr,vector<int> &prev,vector<int> &subseq,int n){
  int max_idx=0;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[j]<arr[i] && prev[i]<prev[j]+1){
        prev[i]=prev[j]+1;
        subseq[i]=j;
      }
    }
    if(prev[max_idx]<prev[i]) max_idx=i;
  }
  return max_idx;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<int> prev(n,1);
  vector<int> subseq(n,-1);
  int idx=LIS(arr,prev,subseq,n);
  vector<int> res;
  cout<<"maximum length: "<<prev[idx]<<endl;
  while(idx!=-1){
    res.push_back(arr[idx]);
    idx=subseq[idx];
  }
  reverse(res.begin(),res.end());
  for(int ele: res) cout<<ele<<" ";
  return 0;
}