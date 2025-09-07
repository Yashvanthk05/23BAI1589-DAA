#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int computeHash(string text,int length,int d,int q){
  int h=0;
  for(int i=0;i<length;i++){
    h=(h*d+text[i])%q;
  }
  return h;
}

void rabinKarp(string text,string pattern,int d,int q){
  int n=text.length();
  int m=pattern.length();
  int h=1;
  for(int i=0;i<m-1;i++){
    h=(h*d)%q;
  }
  int partial_k=ceil(2*m/3);
  int tHash=computeHash(text,m,d,q);
  int pHash=computeHash(pattern,m,d,q);
  for(int s=0;s<=n-m;s++){
    if(tHash==pHash && text.substr(s,m)==pattern){
      cout<<"Full shift: "<<s<<endl;
      cout<<"Parital shift: (s="<<s<<", k="<<m<<")"<<endl;
    }else{
      for(int k=partial_k;k<=m;k++){
        int pPartialHash=computeHash(pattern,k,d,q);
        int tPartialHash=computeHash(text.substr(s,k),k,d,q);
        if(pPartialHash==tPartialHash && text.substr(s,k)==pattern.substr(0,k)){
          cout<<"Parital shift: ("<<s<<","<<k<<")"<<endl;
        }
      }
    }
    if(s<n-m){
      tHash=(d*(tHash-text[s]*h)+text[s+m])%q;
      if(tHash<0) tHash+=q;
    }
  }
}

int main(){
  string text,pattern;
  cin>>text>>pattern;
  int d=256;
  int q=101;
  rabinKarp(text,pattern,d,q);
}