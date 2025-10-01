#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> arr(n+1,vector<int>(n+1,INT_MAX));
  for(int i=1;i<=n;i++) arr[i][i]=0;
  int u,v,w;
  for(int i=0;i<m;i++){
    cin>>u>>v>>w;
    arr[u][v]=min(arr[u][v],w);
    arr[v][u]=min(arr[v][u],w);
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(arr[i][k]!=INT_MAX && arr[k][j]!=INT_MAX)
          arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
      }
    }
  }
  int res=INT_MIN;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(arr[i][j]!=INT_MAX)
        res=max(res,arr[i][j]);
    }
  }
  cout<<res;
  return 0;
}