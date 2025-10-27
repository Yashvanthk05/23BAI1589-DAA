#include<iostream>
#include<vector>
using namespace std;

void backtrack(int n,int start,vector<int> &cur,vector<vector<int>> &res){
  if(n==0){
    res.push_back(cur);
    return;
  }
  for(int i=start;i<=n;i++){
    cur.push_back(i);
    backtrack(n-i,i+1,cur,res);
    cur.pop_back();
  }
}

int main(){
  int n=6;
  vector<vector<int>> res;
  vector<int> cur;
  backtrack(n,1,cur,res);
  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++) cout<<res[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}