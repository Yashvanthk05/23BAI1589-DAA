#include<iostream>
#include<vector>
using namespace std;

string matrices(int i,int j,vector<vector<int>> &splits){
  if(i==j) return "A"+to_string(i);
  return "("+matrices(i,splits[i][j],splits)+"*"+matrices(splits[i][j]+1,j,splits)+")";
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<vector<int>> dp(n,vector<int>(n,0));
  vector<vector<int>> splits(n,vector<int>(n,0));
  for(int l=2;l<n;l++){
    for(int i=1;i<n-l+1;i++){
      int j=i+l-1;
      dp[i][j]=INT_MAX;
      for(int k=i;k<j;k++){
        int cost=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
        if(cost<dp[i][j]){
          dp[i][j]=cost;
          splits[i][j]=k;
        }
      }
    }
  }
  cout<<"Minimum cost: "<<dp[1][n-1]<<"\n";
  cout<<matrices(1,n-1,splits)<<"\n";
  return 0;
}
