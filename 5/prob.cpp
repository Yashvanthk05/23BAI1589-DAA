#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

int CutRodRecursiveTopDown(vector<int> &arr,int length){
  if(length==0) return 0;
  int q=INT_MIN;
  for(int i=1;i<=length;i++){
    q=max(q,arr[i]+CutRodRecursiveTopDown(arr,length-i));
  }
  return q;
}

int CutRodMemoizedAux(vector<int> &arr,int length,vector<int> &dp){
  if(dp[length]>=0) return dp[length];
  int q;
  if(length==0) q=0;
  else{
    q=INT_MIN;
    for(int i=1;i<=length;i++){
      q=max(q,arr[i]+CutRodMemoizedAux(arr,length-i,dp));
    }
  }
  return dp[length]=q;
}

int CutRodMemoized(vector<int> &arr,int length){
  vector<int> dp(length+1,INT_MIN);
  return CutRodMemoizedAux(arr,length,dp);
}

void CutRodBottomUp(vector<int> &arr,int length){
  vector<int> dp(length+1,0);
  vector<int> cuts(length+1,0);
  for(int i=1;i<=length;i++){
    int q=INT_MIN;
    for(int j=1;j<=i;j++){
      if(arr[j]+dp[i-j]>q){
        q=arr[j]+dp[i-j];
        cuts[i]=j;
      }
    }
    dp[i]=q;
  }
  cout<<"Extended Bottom Up: "<<dp[length]<<" (Cuts: ";
  for(int i=length;i>0;i-=cuts[i]){
    cout<<cuts[i]<<" ";
  }
  cout<<")"<<endl;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n+1,0);
  for(int i=1;i<=n;i++) cin>>arr[i];
  int length;
  cin>>length;
  cout<<"Recursive Top Down: "<<CutRodRecursiveTopDown(arr,length)<<endl;
  cout<<"Memoized Top Down: "<<CutRodMemoized(arr,length)<<endl;
  CutRodBottomUp(arr,length);
  return 0;
}

