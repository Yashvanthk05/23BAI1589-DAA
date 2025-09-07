#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int d=256;
int q=7;

int computeHash(string text,int length){
  int h=0;
  for(int i=0;i<length;i++){
    h=(h*d+text[i])%q;
  }
  return h;
}

int rabinKarp(string text,string pattern){
  int n=text.length();
  int m=pattern.length();
  if(m>n) return 0;
  int h=1;
  for(int i=0;i<m-1;i++){
    h=(h*d)%q;
  }
  int tHash=computeHash(text,m);
  int pHash=computeHash(pattern,m);
  int spuriousHits=0;
  for(int s=0;s<=n-m;s++){
    if(pHash==tHash){
      if(text.substr(s,m)!=pattern){
        spuriousHits++;
      }
    }
    if(s<n-m){
      tHash=(d*(tHash-text[s]*h)+text[s+m])%q;
      if(tHash<0) tHash+=q;
    }
  }
  return spuriousHits;
}

int main(){
  int k;
  cin>>k;
  vector<string> texts(k),patterns(k);
  for(int i=0;i<k;i++) cin>>texts[i];
  for(int i=0;i<k;i++) cin>>patterns[i];
  int maxSpurious=INT_MIN,minSpurious=INT_MAX;
  pair<int,int> maxTuple,minTuple;
  for(int i=0;i<k;i++){
    for(int j=0;j<k;j++){
      int spuriousHits=rabinKarp(texts[i],patterns[j]);
      cout<<"Tuple (T"<<i+1<<", P"<<j+1<<") with Spurious Hits="<<spuriousHits<<endl;
      if(spuriousHits>maxSpurious){
        maxSpurious=spuriousHits;
        maxTuple={i+1,j+1};
      }
      if(spuriousHits<minSpurious){
        minSpurious=spuriousHits;
        minTuple={i+1,j+1};
      }
    }
  }
  cout<<"Maximum spurious hits: "<<maxSpurious<<" at tuple (T"<<maxTuple.first<<", P"<<maxTuple.second<<")"<<endl;
  cout<<"Minimum spurious hits: "<<minSpurious<<" at tuple (T"<<minTuple.first<<", P"<<minTuple.second<<")"<<endl;
  return 0;
}

