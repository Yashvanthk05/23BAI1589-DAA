#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define d 256
#define q 101

vector<pair<int,int>> rabinKarpPartial(string text,string pattern){
  int n=text.size();
  int m=pattern.size();
  int t=0,p=0,h=1;
  int klimit=max(1,(int)ceil((2.0*m)/3));
  for(int i=0;i<m-1;i++) h=(h*d)%q;
  for(int i=0;i<m;i++){
    t=(t*d+text[i])%q;
    p=(p*d+pattern[i])%q;
  }
  vector<pair<int,int>> partialShifts;
  for(int s=0;s<=n-m;s++){
    if(p==t){
      if(text.substr(s,m)==pattern){
        cout<<"Full valid shift at: "<<s<<endl;
      }
    }
    for(int k=klimit;k<m;k++){
      if(s+k<n && pattern.substr(0,k)==text.substr(s,k)){
        partialShifts.push_back({s,k});
        break;
      }
    }
    if(s<n-m){
      t=(d*(t-text[s]*h)+text[s+m])%q;
      if(t<0) t+=q;
    }
  }
  return partialShifts;
}

int main(){
  string text,pattern;
  cin>>text>>pattern;
  vector<pair<int,int>> partials=rabinKarpPartial(text,pattern);
  cout<<"Valid Partial Shifts at: ";
  for(pair<int,int> x:partials){
    cout<<"("<<x.first<<","<<x.second<<")"<<" ";
  }
  return 0;
}