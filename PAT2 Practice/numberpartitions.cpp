#include<iostream>
#include<vector>
using namespace std;

void backtrack(int n,int start,int &count,vector<int> &cur,vector<int> &res){
  if(n==0){
    count++;
    if(res.size()<cur.size()){
      res=cur;
    }
    return;
  }
  for(int i=start;i<=n;i++){
    cur.push_back(i);
    backtrack(n-i,i+1,count,cur,res);
    cur.pop_back();
  }
}

int main(){
  int n=6;
  int count=0;
  vector<int> cur,res;
  backtrack(n,1,count,cur,res);
  cout<<"Total Possible Partitions: "<<count<<endl;
  for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
}