#include<iostream>
#include<vector>
using namespace std;

int rodcut(vector<int> price,int length,vector<int> &cutsPos,vector<int> &dp){
  if(length==1) return price[1];
  if(dp[length]!=-1) return dp[length];
  int maxprofit=price[length];
  int cut=-1;
  if(length>=2){
    int mid=length/2;
    int left=rodcut(price,mid,cutsPos,dp);
    int right=rodcut(price,length-mid,cutsPos,dp);
    int profit=left+right;
    if(profit>=maxprofit){
      maxprofit=profit;
      cut=mid;
    }
  }
  cutsPos[length]=cut;
  return dp[length]=maxprofit;
}

void printSeq(vector<int> cutsPos,int n){
  if(n<=1) return;
  if(cutsPos[n]==-1) return;
  cout<<"Optimal Cutting Starts At: "<<cutsPos[n]<<endl;
  printSeq(cutsPos,cutsPos[n]);
  printSeq(cutsPos,n-cutsPos[n]);
}

int main(){
  int length;
  cin>>length;
  vector<int> price(length+1);
  for(int i=1;i<=length;i++) cin>>price[i];
  vector<int> cutsPos(length+1,-1);
  vector<int> dp(length+1,-1);
  cout<<"Maximum Profit: "<<rodcut(price,length,cutsPos,dp)<<endl;
  printSeq(cutsPos,length);
  return 0;
}