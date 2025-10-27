#include<iostream>
using namespace std;

#define d 256
#define q 101

void rabinKarp(string text,string pattern){
  int n=text.size();
  int m=pattern.size();
  int t=0,p=0;
  int h=1;
  for(int i=0;i<m-1;i++) h=(h*d)%q;
  for(int i=0;i<m;i++){
    t=(t*d+text[i])%q;
    p=(p*d+pattern[i])%q;
  }
  for(int s=0;s<=n-m;s++){
    if(p==t){
      if(text.substr(s,m)==pattern){
        cout<<"Pattern found at shift/index: "<<s<<endl;
      }
    }
    if(s<n-m){
      t=(d*(t-text[s]*h)+text[s+m])%q;
      if(t<0){
        t=(t+q);
      }
    }
  }
}

int main(){
  string text,pattern;
  cin>>text>>pattern;
  rabinKarp(text,pattern);
  return 0;
}