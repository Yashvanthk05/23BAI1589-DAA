#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

#define d 256
#define q 101

void rabinKarp(string text,string pattern){
  int n=text.size();
  int m=pattern.size();
  int t=0,p=0,h=1;
  for(int i=0;i<m-1;i++) h=(h*d)%q;
  for(int i=0;i<m;i++){
    p=(d*p+pattern[i])%q;
    t=(d*t+text[i])%q;
  }
  int klimit=ceil((2*m)/3);
  vector<pair<int,int>> partialShifts;
  for(int s=0;s<=n-m;s++){
    if(t==p){
      if(pattern==text.substr(s,m)){
        cout<<"Full valid shift at: "<<s<<endl;
      }
    }
    for(int k=m-1;k>=klimit;k--){
      if(s+k<=n && pattern.substr(0,k)==text.substr(s,k)){
        partialShifts.push_back({s,k});
        break;
      }
    }
    if(s<n-m){
      t=(d*(t-text[s]*h)+text[s+m])%q;
      if(t<0) t=t+q;
    }
  }

  for(pair<int,int> p: partialShifts){
    cout<<"Partial Shift at: "<<p.first<<" "<<p.second<<endl;
  }
}

int main(){
  string text,pattern;
  cin>>text>>pattern;
  rabinKarp(text,pattern);
}