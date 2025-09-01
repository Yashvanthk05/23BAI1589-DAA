#include<iostream>
#include<vector>
using namespace std;

vector<pair<string,int>> MCMRecursion(vector<int> &arr,int i,int j){
  vector<pair<string,int>> res;
  if(i==j){
    res.push_back({"A"+to_string(i),0});
    return res;
  }
  for(int k=i;k<j;k++){
    vector<pair<string,int>> left=MCMRecursion(arr,i,k);
    vector<pair<string,int>> right=MCMRecursion(arr,k+1,j);
    for(pair<string,int> l:left){
      for(pair<string,int> r:right){
        int cost=l.second+r.second+arr[i-1]*arr[k]*arr[j];
        res.push_back({"("+l.first+"*"+r.first+")",cost});
      }
    }
  }
  return res;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<pair<string,int>> res=MCMRecursion(arr,1,n-1);
  for(pair<string,int> i:res){
    cout<<i.first<<"\n"<<i.second<<"\n";
  }
  return 0;
}

