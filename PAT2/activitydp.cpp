#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Activity{
  int start;
  int end;
};

int main(){
  int n;
  cin>>n;
  vector<Activity> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i].start>>arr[i].end;
  vector<int> dp(n,1);
  sort(arr.begin(),arr.end(),[](Activity a,Activity b){
    return a.end<b.end;
  });
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[j].end<arr[i].start){
        dp[i]=max(dp[i],dp[j]+1);
      }
    }
  }
  cout<<*max_element(dp.begin(),dp.end());
}