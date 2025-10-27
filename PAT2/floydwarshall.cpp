#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> arr(n+1,vector<int>(n+1,INT_MAX));
  for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    arr[u][v]=w;
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(arr[i][k]!=INT_MAX && arr[k][j]!=INT_MAX)
          arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(arr[i][j]==INT_MAX) cout<<"inf"<<" ";
      else cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}