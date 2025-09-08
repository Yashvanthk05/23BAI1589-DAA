#include<iostream>
#include<vector>
using namespace std;

int rodCutRecur(vector<int> price,int length,vector<int> &cutsPos){
  if(length==0) return 0;
  int maxprofit=INT_MIN;
  for(int i=1;i<=min(length,(int)price.size());i++){
    int profit=price[i-1]+rodCutRecur(price,length-i,cutsPos);
    if(profit>maxprofit){
      maxprofit=profit;
      cutsPos[length]=i;
    }
  }
  return maxprofit;
}

int rodCutMemo(vector<int> price,int length,vector<int> &cutsPos,vector<int> &dp){
  if(length==0) return 0;
  if(dp[length]!=-1) return dp[length];
  int maxprofit=INT_MIN;
  for(int i=1;i<=min((int)price.size(),length);i++){
    int profit=price[i-1]+rodCutMemo(price,length-i,cutsPos,dp);
    if(profit>maxprofit){
      maxprofit=profit;
      cutsPos[length]=i;
    }
  }
  return dp[length]=maxprofit;
}

int rodCutTabu(vector<int> price,int length,vector<int> &cutsPos){
  vector<int> dp(length+1,0);
  for(int i=1;i<=length;i++){
    int maxprofit=INT_MIN;
    for(int j=1;j<=min(i,(int)price.size());j++){
      int profit=price[j-1]+dp[i-j];
      if(profit>maxprofit){
        maxprofit=profit;
        cutsPos[i]=j;
      }
    }
    dp[i]=maxprofit;
  }
  return dp[length];
}

int main(){
  int n;
  cin>>n;
  vector<int> price(n);
  for(int i=0;i<n;i++) cin>>price[i];
  int length;
  cin>>length;
  vector<int> cutsPos(length+1,-1);
  // cout<<rodCutRecur(price,length,cutsPos)<<endl;
  // vector<int> dp(length+1,-1);
  // cout<<rodCutMemo(price,length,cutsPos,dp)<<endl;
  cout<<rodCutTabu(price,length,cutsPos)<<endl;
  int idx=length;
  while(idx>0){
    cout<<cutsPos[idx]<<" ";
    idx-=cutsPos[idx];
  }
  return 0;
}