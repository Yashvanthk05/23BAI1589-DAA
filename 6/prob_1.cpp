#include<iostream>
#include<vector>
using namespace std;

int LCSmemo(string x,string y,int m,int n,vector<vector<int>> &dp){
  if(m==0 || n==0) return 0;
  if(dp[m][n]!=-1) return dp[m][n];
  if(x[m-1]==y[n-1]){
    dp[m][n]=1+LCSmemo(x,y,m-1,n-1,dp);
  }else{
    dp[m][n]=max(LCSmemo(x,y,m-1,n,dp),LCSmemo(x,y,m,n-1,dp));
  }
  return dp[m][n];
}

string LCSstring(string x,string y,int m,int n,vector<vector<int>> &dp){
  string st="";
  while(m>0 && n>0){
    if(x[m-1]==y[n-1]){
      st=x[m-1]+st;
      m--;
      n--;
    }else{
      if(dp[m][n-1]>dp[m-1][n]){
        n--;
      }else{
        m--;
      }
    }
  }
  return st;
}

int main(){
  string x,y;
  cout<<"Enter String1: ";
  cin>>x;
  cout<<"Enter String2: ";
  cin>>y;
  int m=x.size();
  int n=y.size();
  vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
  int lcslen=LCSmemo(x,y,m,n,dp);
  string st=LCSstring(x,y,m,n,dp);
  cout<<"Longest Common Subsequence String: "<<st<<endl;
  cout<<"Longest Common Subsequence Length: "<<lcslen;
  return 0;
}

