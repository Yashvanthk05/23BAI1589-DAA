#include<iostream>
#include<vector>
using namespace std;

vector<int> computeLPS(string pattern){
  int n=pattern.size();
  vector<int> LPS(n,0);
  int i=0,j=1;
  while(j<n){
    if(pattern[i]==pattern[j]){
      i++;
      LPS[j]=i;
      j++;
    }else{
      if(i==0){
        LPS[j]=0;
        j++;
      }else{
        i=LPS[i-1];
      }
    }
  }
  return LPS;
}

void KMP(string text,string pattern){
  int n=text.size();
  int m=pattern.size();
  vector<int> LPS=computeLPS(pattern);
  int i=0,j=0;
  while(i<n){
    if(text[i]==pattern[j]){
      i++;
      j++;
    }
    if(j==m){
      cout<<"Pattern found at index: "<<i-j<<endl;
      j=LPS[j-1];
    }else if(i<n && text[i]!=pattern[j]){
      if(j==0){
        i++;
      }else{
        j=LPS[j-1];
      }
    }
  }
}

int main(){
  string text,pattern;
  cin>>text>>pattern;
  KMP(text,pattern);
  return 0;
}