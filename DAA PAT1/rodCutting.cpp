#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int rodCutRecur(vector<int> price,vector<int> length,int n,vector<int> &cutsPos,int cutCost){
  if(n==0) return 0;
  int maxprofit=INT_MIN;
  for(int i=0;i<length.size();i++){
    if(length[i]<=n){
      int profit=price[i]+rodCutRecur(price,length,n-length[i],cutsPos,cutCost);
      if(length[i]!=n) profit-=cutCost;
      if(profit>maxprofit){
        maxprofit=profit;
        cutsPos[n]=length[i];
      }
    }
  }
  return maxprofit;
}

int rodCutMemo(vector<int> price,vector<int> length,int n,vector<int> &cutsPos,vector<int> &dp,int cutCost){
  if(n==0) return 0;
  if(dp[n]!=-1) return dp[n];
  int maxprofit=INT_MIN;
  for(int i=0;i<length.size();i++){
    if(length[i]<=n){
      int profit=price[i]+rodCutMemo(price,length,n-length[i],cutsPos,dp,cutCost);
      if(length[i]!=n) profit-=cutCost;
      if(profit>maxprofit){
        maxprofit=profit;
        cutsPos[n]=length[i];
      }
    }
  }
  return dp[n]=maxprofit;
}

int rodCutTabu(vector<int> price,vector<int> length,int n,vector<int> &cutsPos,int cutCost){
  vector<int> dp(n+1,0);
  for(int i=1;i<=n;i++){
    int maxprofit=INT_MIN;
    for(int j=0;j<length.size();j++){
      if(length[j]<=i){
        int profit=price[j]+dp[i-length[j]];
        if(length[j]!=i) profit-=cutCost;
        if(profit>maxprofit){
          maxprofit=profit;
          cutsPos[i]=length[j];
        }
      }
    }
    dp[i]=maxprofit;
  }
  return dp[n];
}

int main(){
  int n;
  cin>>n;
  vector<int> price(n),length(n);
  for(int i=0;i<n;i++) cin>>length[i];
  for(int i=0;i<n;i++) cin>>price[i];
  int l;
  cin>>l;
  vector<int> cutsPos(l+1,-1);
  int cutCost;
  cin>>cutCost;
  // 10
  // 1 2 3 4 5 6 7 8 9 10
  // 1 5 8 9 10 17 17 20 24 30
  // 4
  // cout<<rodCutRecur(price,length,l,cutsPos,cutCost)<<endl;
  // vector<int> dp(l+1,-1);
  // cout<<rodCutMemo(price,length,l,cutsPos,dp,cutCost)<<endl;
  cout<<rodCutTabu(price,length,l,cutsPos,cutCost)<<endl;
  int idx=l;
  while(idx>0){
    cout<<cutsPos[idx]<<" ";
    idx-=cutsPos[idx];
  }
  cout<<endl;
  return 0;
}