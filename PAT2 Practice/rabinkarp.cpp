#include<iostream>
#include<vector>
using namespace std;

#define d 10
#define q 101

void rabinKarp(string text,string pattern){
  int n=text.size();
  int m=pattern.size();
  int p=0,t=0,h=1;
  for(int i=0;i<m-1;i++) h=(h*d)%q;
  for(int i=0;i<m;i++){
    p=(p*d+pattern[i])%q;
    t=(t*d+text[i])%q;
  }
  for(int s=0;s<=n-m;s++){
    if(p==t){
      if(pattern==text.substr(s,m)){
        cout<<"Match Found at index: "<<s;
      }
    }
    if(s<n-m){
      t=(d*(t-h*text[s])+text[s+m])%q;
      if(t<0) t=t+q;
    }
  }
}

int main(){
  string text,pattern;
  cin>>text>>pattern;
  rabinKarp(text,pattern);
  return 0;
}