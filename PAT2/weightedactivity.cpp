#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Activity{
  int start;
  int finish;
  int value;
};

int main(){
  int n;
  cin>>n;
  vector<Activity> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i].start>>arr[i].finish>>arr[i].value;
  sort(arr.begin(),arr.end(),[](Activity a,Activity b){
    return a.finish<b.finish;
  });
  vector<int> dp(n);
  for(int i=0;i<n;i++) dp[i]=arr[i].value;
  vector<int> prev(n,-1);
  int maxvalue=dp[0],maxidx=0;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(dp[j]+arr[i].value>dp[i] && arr[j].finish<=arr[i].start){
        dp[i]=dp[j]+arr[i].value;
        prev[i]=j;
      }
    }
    if(maxvalue<dp[i]){
      maxvalue=dp[i];
      maxidx=i;
    }
  }
  int idx=maxidx;
  vector<int> res;
  while(idx!=-1){
    res.push_back(idx+1);
    idx=prev[idx];
  }
  for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
  return 0;
}