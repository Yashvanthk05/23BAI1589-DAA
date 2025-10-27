#include<iostream>
#include<vector>
#include<climits>
using namespace std;

string matrices(int i,int j,vector<vector<int>> &splits){
  if(i==j) return "A"+to_string(i);
  return "("+matrices(i,splits[i][j],splits)+"*"+matrices(splits[i][j]+1,j,splits)+")";
}

int MCMRecur(vector<int> arr,int i,int j,vector<vector<int>> &splits){
  if(i==j) return 0;
  int min_cost=INT_MAX;
  for(int k=i;k<j;k++){
    int cost=MCMRecur(arr,i,k,splits)+MCMRecur(arr,k+1,j,splits)+arr[i-1]*arr[k]*arr[j];
    if(cost<min_cost){
      min_cost=cost;
      splits[i][j]=k;
    }
  }
  return min_cost;
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

int MCMTabu(vector<int> arr,int n,vector<vector<int>> &splits){
  vector<vector<int>> dp(n,vector<int>(n,0));
  for(int l=2;l<n;l++){
    for(int i=1;i<n-l+1;i++){
      int j=i+l-1;
      dp[i][j]=INT_MAX;
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
  cout<<"Minimum Cost (Recursion): "<<MCMRecur(arr,1,n-1,splits)<<endl;
  vector<vector<int>> dp(n,vector<int>(n,-1));
  cout<<"Minimum Cost (Memoization): "<<MCMMemo(arr,1,n-1,splits,dp)<<endl;
  cout<<"Minimum Cost (Tabulation): "<<MCMTabu(arr,n,splits)<<endl;
  cout<<matrices(1,n-1,splits)<<endl;
  return 0;
}