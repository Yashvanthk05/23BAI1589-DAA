#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int rodCutttingRecTopDown(vector<int> &arr,int length,int cost){
  if(length==0) return 0;
  int max_val=INT_MIN;
  for(int i=1;i<=length;i++){
    int val=arr[i-1]+rodCutttingRecTopDown(arr,length-i,cost);
    if(i!=length) val-=cost;
    max_val=max(max_val,val);
  }
  return max_val;
}

int rodCuttingMemo(vector<int> &arr,int length,int cost,unordered_map<int,int> &dp){
  if(length==0) return 0;
  if(dp.count(length)) return dp[length];
  int max_val=INT_MIN;
  for(int i=1;i<=length;i++){
    int val=arr[i-1]+rodCuttingMemo(arr,length-i,cost,dp);
    if(i!=length) val-=cost;
    max_val=max(max_val,val);
  }
  return dp[length]=max_val;
}

int rodCuttingBottomUp(vector<int> &arr,int length,int cost){
  vector<int> dp(length+1,0);
  vector<int> cuts(length+1,0);
  for(int i=1;i<=length;i++){
    int max_val=INT_MIN;
    for(int j=1;j<=i;j++){
      int val=arr[j-1]+dp[i-j];
      if(j!=i) val-=cost;
      if(val>max_val){
        max_val=val;
        cuts[i]=j;
      }
    }
    dp[i]=max_val;
  }
  int temp=length;
  cout<<"(Cuts: ";
  while(temp>0){
    cout<<cuts[temp]<<" ";
    temp-=cuts[temp];
  }
  cout<<") ";
  return dp[length];
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) {
    cin>>arr[i];
  }
  int length,costcut;
  cout<<"Rod Length: ";
  cin>>length;
  cout<<"Cutting Cost: ";
  cin>>costcut;
  cout<<"Recursive Top-Down Revenue: "<<rodCutttingRecTopDown(arr,length,costcut)<<endl;
  unordered_map<int,int> dp;
  cout<<"Memoized Top-Down Revenue: "<<rodCuttingMemo(arr,length,costcut,dp)<<endl;
  cout<<"Extended Bottom-Up Revenue: "<<rodCuttingBottomUp(arr,length,costcut)<<endl;
  return 0;
}
