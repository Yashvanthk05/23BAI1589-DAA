#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void LIS(vector<int> arr,int n,vector<int> &dp,vector<int> &prev){
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[j]<arr[i]){
        if(dp[i]<dp[j]+1){
          dp[i]=dp[j]+1;
          prev[i]=j;
        }
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<int> dp(n,1);
  vector<int> prev(n,-1);
  LIS(arr,n,dp,prev);
  int maxindex=0;
  int maxval=dp[0];
  for(int i=1;i<n;i++){
    if(dp[i]>maxval){
      maxindex=i;
      maxval=dp[i];
    }
  }
  vector<int> lisele;
  int i=maxindex;
  while(i!=-1){
    lisele.push_back(arr[i]);
    i=prev[i];
  }
  reverse(lisele.begin(),lisele.end());
  cout<<"Longest Increasing Subsequence: ";
  for(int ele:lisele) cout<<ele<<" ";
  cout<<endl;
  cout<<"Length: "<<maxval<<endl;
  return 0;
}


