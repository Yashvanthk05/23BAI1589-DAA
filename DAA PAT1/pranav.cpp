#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  int m;
  cin>>m;
  vector<int> arr(m);
  for(int i=0;i<m;i++) cin>>arr[i];
  vector<int> dp(n+1,0);
  for(int i=1;i<=n;i++){
    int mini=i;
    for(int j=0;j<arr.size();j++){
      if(arr[j]<=i) mini=min(mini,arr[j]+dp[i-arr[j]]);
    }
    dp[i]=mini;
  }
  int totalcost=0;
  int length=n;
  for(int i=0;i<m;i++){
    if(length>0){
      totalcost+=dp[length];
      length-=arr[i];
    }
  }
  cout<<totalcost<<endl;
}