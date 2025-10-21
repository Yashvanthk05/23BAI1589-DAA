#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

bool dfs(int u,int t,vector<int> &path,vector<bool> &visited,vector<vector<int>> &adj,vector<vector<int>> &flow,vector<vector<int>> &capacity){
  if(u==t) return true;
  visited[u]=true;
  for(int v:adj[u]){
    if(!visited[v] && capacity[u][v]-flow[u][v]>0){
      path.push_back(v);
      if(dfs(v,t,path,visited,adj,flow,capacity)) return true;
      path.pop_back();
    }
  }
  return false;
}

int maxFlow(int s,int t,int n,vector<vector<int>> &adj,vector<vector<int>> &capacity){
  vector<vector<int>> flow(n,vector<int>(n,0));
  int totalmaxflow=0;
  while(true){
    vector<bool> visited(n,false);
    vector<int> path;
    path.push_back(s);
    if(!dfs(s,t,path,visited,adj,flow,capacity)) break;
    int augmented=INT_MAX;
    for(int i=0;i<path.size()-1;i++){
      int u=path[i],v=path[i+1];
      augmented=min(augmented,capacity[u][v]-flow[u][v]);
    }
    for(int i=0;i<path.size()-1;i++){
      int u=path[i],v=path[i+1];
      flow[u][v]+=augmented;
      flow[v][u]-=augmented;
    }
    totalmaxflow+=augmented;
  }
  return totalmaxflow;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> capacity(n,vector<int>(n,0));
  vector<vector<int>> adj(n);
  for(int i=0;i<m;i++){
    int u,v,c;
    cin>>u>>v>>c;
    u--;
    v--;
    capacity[u][v]=c;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int s,t;
  cin>>s>>t;
  s--;
  t--;
  cout<<"Maximum flow: "<<maxFlow(s,t,n,adj,capacity);
  return 0;
}
