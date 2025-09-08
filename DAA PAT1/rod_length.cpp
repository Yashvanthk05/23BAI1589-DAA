#include<iostream>
#include<vector>
using namespace std;

int RodCutRec(vector<int> p,vector<int> l,int length,vector<int> &cuts,int cutcost){
  if(length==0) return 0;
  int maxprofit=0;
  for(int i=0;i<l.size();i++){
    if(l[i]<=length){
      int profit=p[i]+RodCutRec(p,l,length-l[i],cuts,cutcost);
      if(length!=l[i]) profit-=cutcost;
      if(profit>maxprofit){
        maxprofit=profit;
        cuts[length]=l[i];
      }
    }
  }
  return maxprofit;
}

int RodCutMemo(vector<int> p,vector<int> l,int length,vector<int> &dp,vector<int> &cuts,int cutcost){
  if(length==0) return 0;
  if(dp[length]!=-1) return dp[length];
  int maxprofit=0;
  for(int i=0;i<l.size();i++){
    if(l[i]<=length){
      int profit=p[i]+RodCutMemo(p,l,length-l[i],dp,cuts,cutcost);
      if(length!=l[i]) profit-=cutcost;
      if(profit>maxprofit){
        maxprofit=profit;
        cuts[length]=l[i];
      }
    }  
  }
  return dp[length]=maxprofit;
}

int RodCutTabu(vector<int> p,vector<int> l,int length,vector<int> &cuts,int cutcost){
  vector<int> dp(length+1,0);
  for(int i=1;i<=length;i++){
    int maxprofit=INT_MIN;
    for(int j=0;j<l.size();j++){
      if(l[j]<=i){
        int profit=p[j]+dp[i-l[j]];
        if(i!=l[j]) profit-=cutcost;
        if(profit>maxprofit){
          maxprofit=profit;
          cuts[i]=l[j];
        }
      }
    }
    dp[i]=maxprofit;
  }
  return dp[length];
}

int main(){
  vector<int> p={1,5,8,9,10,17,17,20,24,30};
  vector<int> l={1,2,3,4,5,6,7,8,9,10};
  int cutcost=0;
  int length=8;
  vector<int> cuts(length+1,-1);
  cout<<"Recursive: "<<RodCutRec(p,l,length,cuts,cutcost)<<endl;
  vector<int> dp(length+1,-1);
  //cout<<"Memoized: "<<RodCutMemo(p,l,length,dp,cuts,cutcost)<<endl;
  //cout<<"Tabulation: "<<RodCutTabu(p,l,length,cuts,cutcost)<<endl;
  int n=length;
  while(n>0){
    cout<<cuts[n]<<" ";
    n-=cuts[n];
  }
  cout<<endl;
  return 0;
}