#include<iostream>
#include<vector>
using namespace std;

int MCMRecur(vector<int> arr,int i,int j,vector<vector<int>> &splits){
  if(i==j) return 0;
  int mincost=INT_MAX;
  for(int k=i;k<j;k++){
    int cost=MCMRecur(arr,i,k,splits)+MCMRecur(arr,k+1,j,splits)+arr[i-1]*arr[k]*arr[j];
    if(cost<mincost){
      mincost=cost;
      splits[i][j]=k;
    }
  }
  return mincost;
}

string MCMString(int i,int j,vector<vector<int>> splits){
  if(i==j) return "A"+to_string(i);
  return "("+MCMString(i,splits[i][j],splits)+"*"+MCMString(splits[i][j]+1,j,splits)+")";
}

int MCMMemo(vector<int> arr,int i,int j,vector<vector<int>> &splits,vector<vector<int>> &dp){
  if(i==j) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  dp[i][j]=INT_MAX;
  for(int k=i;k<j;k++){
    int cost=MCMMemo(arr,i,k,splits,dp)+MCMMemo(arr,k+1,j,splits,dp)+arr[i-1]*arr[k]*arr[j];
    if(cost<dp[i][j]){
      dp[i][j]=cost;
      splits[i][j]=k;
    }
  }
  return dp[i][j];
}

int MCMTabu(vector<int> arr,int i,int j,vector<vector<int>> &splits){
  int n=arr.size();
  vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
  for(int i=0;i<n;i++) dp[i][i]=0;
  for(int i=n-1;i>=1;i--){
    for(int j=i+1;j<n;j++){
      for(int k=i;k<j;k++){
        int cost=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
        if(cost<dp[i][j]){
          dp[i][j]=cost;
          splits[i][j]=k;
        }
      }
    }
  }
  return dp[1][n-1];
}

int MCMTabu2(vector<int> arr,int n,vector<vector<int>> &splits){
  vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
  for(int i=0;i<n;i++) dp[i][i]=0;
  for(int l=2;l<n;l++){
    for(int i=1;i<n-l+1;i++){
      int j=i+l-1;
      for(int k=i;k<j;k++){
        int cost=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
        if(cost<dp[i][j]){
          dp[i][j]=cost;
          splits[i][j]=k;
        }
      }
    }
  }
  return dp[1][n-1];
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<vector<int>> splits(n,vector<int>(n,0));
  // cout<<"Recursion Cost: "<<MCMRecur(arr,1,n-1,splits)<<endl;
  vector<vector<int>> dp(n,vector<int>(n,-1));
  //cout<<"Memoization: "<<MCMMemo(arr,1,n-1,splits,dp)<<endl;
  cout<<"Tabulation: "<<MCMTabu2(arr,n,splits)<<endl;
  cout<<MCMString(1,n-1,splits);
  return 0;
}