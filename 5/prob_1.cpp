#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int rodCutttingRecTopDown(vector<int> &arr,int length){
  if(length==0) return 0;
  int max_val=INT_MIN;
  for(int i=1;i<=length;i++){
    max_val=max(max_val,arr[i-1]+rodCutttingRecTopDown(arr,length-i));
  }
  return max_val;
}

int rodCuttingMemo(vector<int> &arr,int length,unordered_map<int,int> &dp){
  if(length==0) return 0;
  if(dp.count(length)!=-1) return dp[length];
  int max_val=INT_MIN;
  for(int i=1;i<=length;i++){
    max_val=max(max_val,arr[i-1]+rodCuttingMemo(arr,length-i,dp));
  }
  return dp[length]=max_val;
}

int rodCuttingBottomUp(vector<int> &arr,int length){
  vector<int> dp(length+1,0);
  vector<int> cuts(length+1,0);
  for(int i=1;i<=length;i++){
    int max_val=INT_MIN;
    for(int j=1;j<=i;j++){
      if(arr[j-1]+dp[i-j]>max_val){
        max_val=arr[j-1]+dp[i-j];
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
  int length;
  cout<<"Rod Length: ";
  cin>>length;
  cout<<"Recursive Top-Down Revenue: "<<rodCutttingRecTopDown(arr,length)<<endl;
  unordered_map<int,int> dp;
  cout<<"Memoized Top-Down Revenue: "<<rodCuttingMemo(arr,length,dp)<<endl;
  cout<<"Extended Bottom-Up Revenue: "<<rodCuttingBottomUp(arr,length)<<endl;
  return 0;
}

