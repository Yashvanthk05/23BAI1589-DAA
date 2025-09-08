#include<iostream>
#include<vector>
using namespace std;

int rodcut(vector<int> price,int length,vector<int> &cutsPos){
  if(length==1) return price[0];
  int maxprofit=price[length-1];
  if(length>=2){
    int mid=length/2;
    int left=rodcut(price,mid,cutsPos);
    int right=rodcut(price,length-mid,cutsPos);
    int total=left+right;
    if(total>maxprofit){
      maxprofit=total;
      cutsPos[length]=mid;
    }
  }
  return maxprofit;
}

void printcuts(vector<int> cutsPos,int length){
  if(length<=1 || cutsPos[length]==-1) return;
  cout<<"Optimal Cutting: "<<cutsPos[length]<<endl;
  printcuts(cutsPos,cutsPos[length]);
  printcuts(cutsPos,length-cutsPos[length]);
}

int main(){
  int n;
  cin>>n;
  vector<int> price(n);
  for(int i=0;i<n;i++) cin>>price[i];
  vector<int> cutsPos(n+1,-1);
  cout<<rodcut(price,n,cutsPos)<<endl;
  printcuts(cutsPos,n);
  return 0;
}