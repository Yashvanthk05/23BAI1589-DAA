#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int u,int t,vector<int> &path,vector<vector<int>> &adj,vector<vector<double>> &capacity,vector<vector<int>> &flow,vector<int> &dist){
  path.push_back(u+1);
  if(u==t){
    for(int i=0;i<path.size();i++){
      cout<<path[i]<<(i==path.size()-1?"":" -> ");
    }
    cout<<endl;
  }else{
    for(int v:adj[u]){
      if(capacity[u][v]-flow[u][v]>0 && dist[v]==dist[u]+1){
        dfs(v,t,path,adj,capacity,flow,dist);
      }
    }
  }
  path.pop_back();
}

void bfs(int s,vector<int> &dist,vector<vector<int>> &adj,vector<vector<double>> &capacity,vector<vector<int>> &flow){
  queue<int> q;
  q.push(s);
  dist[s]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int v:adj[u]){
      if(dist[v]==-1 && capacity[u][v]-flow[u][v]>0){
        dist[v]=dist[u]+1;
        q.push(v);
      }
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<double>> capacity(n,vector<double>(n,0));
  vector<vector<int>> adj(n);
  for(int i=0;i<m;i++){
    int u,v,c;
    cin>>u>>v>>c;
    u--;
    v--;
    capacity[u][v]=c;
    adj[u].push_back(v);
  }
  vector<vector<int>> flow(n,vector<int>(n,0));
  int s,t;
  cin>>s>>t;
  s--;
  t--;
  vector<int> dist(n,-1);
  bfs(s,dist,adj,capacity,flow);
  int len=dist[t];
  if(len==-1){
    cout<<"No augmenting paths";
  }else{
    vector<int> path;
    cout<<"Augmenting Paths:"<<endl;
    dfs(s,t,path,adj,capacity,flow,dist);
  }
  return 0;
}

