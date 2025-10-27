#include<iostream>
using namespace std;

int main(){
  string x,y;
  cin>>x>>y;
  int n=x.size(),m=y.size();
  for(int i=0;i<=n-m;i++){
    int j=0;
    while(j<m && x[i+j]==y[j]){
    }
    if(j==m) cout<<"Index: "<<i<<endl;
  }
}