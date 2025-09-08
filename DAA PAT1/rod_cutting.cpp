#include<iostream>
#include<vector>
using namespace std;

int RodCutRec(vector<int> p,int length){
  if(length==0) return 0;
  int maxprofit=INT_MIN;
  for(int i=1;i<=length;i++){
    maxprofit=max(maxprofit,p[i-1]+RodCutRec(p,length-i));
  }
  return maxprofit;
}

int RodCutMemo(vector<int> p,int length,vector<int> &dp){
  if(length==0) return 0;
  if(dp[length]!=-1) return dp[length];
  int maxprofit=INT_MIN;
  for(int i=1;i<=length;i++){
    maxprofit=max(maxprofit,p[i-1]+RodCutMemo(p,length-i,dp));
  }
  dp[length]=maxprofit;
  return maxprofit;
}

int RodCutTabu(vector<int> p,int length,vector<int> &cuts){
  vector<int> dp(length+1,0);
  for(int i=1;i<=length;i++){
    int maxprofit=INT_MIN;
    int cutpos=-1;
    for(int j=1;j<=i;j++){
      if((p[j-1]+dp[i-j])>maxprofit){
        maxprofit=p[j-1]+dp[i-j];
        cutpos=j;
      }
    }
    dp[i]=maxprofit;
    cuts[i]=cutpos;
  }
  return dp[length];
}

int main(){
  vector<int> p={1,5,8,9,10,17,17,20,24,30};
  //cout<<RodCutRec(p,4)<<endl;
  vector<int> dp(p.size()+1,-1);
  int length=4;
  //cout<<RodCutMemo(p,4,dp)<<endl;
  vector<int> cuts(length+1,-1);
  cout<<RodCutTabu(p,length,cuts)<<endl;
  int n=length;
  while(n>0){
    cout<<cuts[n]<<" ";
    n-=cuts[n];
  }
  cout<<endl;
  return 0;
}