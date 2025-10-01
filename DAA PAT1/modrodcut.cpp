#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> length={3,5};
  vector<int> price={3,5};
  int n=97;
  vector<int> dp(n+1,0);
  dp[0]=0,dp[1]=-1,dp[2]=-2;
  for(int i=3;i<=n;i++){
    int maxprofit=INT_MIN;
    for(int j=0;j<length.size();j++){
      if(length[j]<=i){
        maxprofit=max(maxprofit,price[j]+dp[i-length[j]]);
      }
    }
    dp[i]=maxprofit;
  }
  cout<<"Maximum Profit: "<<dp[n]<<endl;
  return 0;
}