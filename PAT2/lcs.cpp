#include<iostream>
#include<vector>
using namespace std;

int LCSRecur(string x,string y,int n,int m){
  if(n==0 || m==0) return 0;
  if(x[n-1]==y[m-1]){
    return 1+LCSRecur(x,y,n-1,m-1);
  }
  return max(LCSRecur(x,y,n-1,m),LCSRecur(x,y,n,m-1));
}

string LCSstring(string x,string y,int n,int m,vector<vector<int>> dp){
  string st="";
  while(n>0 && m>0){
    if(x[n-1]==y[m-1]){
      st=x[n-1]+st;
      n--;
      m--;
    }else{
      if(dp[n][m-1]>dp[n-1][m]){
        m--;
      }else{
        n--;
      }
    }
  }
  return st;
}

int LCSMemo(string x,string y,int n,int m,vector<vector<int>> &dp){
  if(n==0 || m==0) return 0;
  if(dp[n][m]!=-1) return dp[n][m];
  if(x[n-1]==y[m-1]){
    dp[n][m]=1+LCSMemo(x,y,n-1,m-1,dp);
  }else{
    dp[n][m]=max(LCSMemo(x,y,n-1,m,dp),LCSMemo(x,y,n,m-1,dp));
  }
  return dp[n][m];
}

int LCSTabu(string x,string y,int n,int m,vector<vector<int>> &dp){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(x[i-1]==y[j-1]){
        dp[i][j]=1+dp[i-1][j-1];
      }else{
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
      }
    }
  }
  return dp[n][m];
}

int main(){
  string x,y;
  cin>>x>>y;
  int n=x.size();
  int m=y.size();
  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
  cout<<LCSTabu(x,y,n,m,dp)<<endl;
  cout<<LCSstring(x,y,n,m,dp);
  return 0;
}