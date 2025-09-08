#include<iostream>
#include<vector>
using namespace std;

int chocoCutTabu(vector<vector<int>> price,int m,int n){
  vector<vector<int>> dp(m+1,vector<int>(n+1,0));
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      int maxprofit=price[i][j];
      for(int k=1;k<i;k++){
        maxprofit=max(maxprofit,dp[k][j]+dp[i-k][j]);
      }
      for(int k=1;k<j;k++){
        maxprofit=max(maxprofit,dp[i][k]+dp[i][j-k]);
      }
      dp[i][j]=maxprofit;
    }
  }
  return dp[m][n];
}

int main(){
  int m,n;
  cin>>m>>n;
  vector<vector<int>> price(m+1,vector<int>(n+1,0));
  for(int i=1;i<m+1;i++){
    for(int j=1;j<n+1;j++){
      cin>>price[i][j];
    }
  }
  cout<<chocoCutTabu(price,m,n)<<endl;
  return 0;
}