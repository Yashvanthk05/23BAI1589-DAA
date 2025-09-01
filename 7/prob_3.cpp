#include<iostream>
#include<vector>
using namespace std;

string matrices(int i,int j,vector<vector<int>> splits){
  if(i==j) return "A"+to_string(i);
  return "("+matrices(i,splits[i][j],splits)+"*"+matrices(splits[i][j]+1,j,splits)+")";
}

int MCMmemo(vector<int> arr,int i,int j,vector<vector<int>> &dp,vector<vector<int>> &splits){
  if(i==j) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  dp[i][j]=INT_MAX;
  for(int k=i;k<j;k++){
    int cost=MCMmemo(arr,i,k,dp,splits)+MCMmemo(arr,k+1,j,dp,splits)+arr[i-1]*arr[k]*arr[j];
    if(cost<dp[i][j]){
      dp[i][j]=cost;
      splits[i][j]=k;
    }
  }
  return dp[i][j];
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<vector<int>> dp(n,vector<int>(n,-1)),splits(n,vector<int>(n,0));
  cout<<MCMmemo(arr,1,n-1,dp,splits)<<"\n";
  cout<<matrices(1,n-1,splits)<<"\n";
  return 0;
}

