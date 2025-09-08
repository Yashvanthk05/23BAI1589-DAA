#include<iostream>
#include<cmath>
using namespace std;

int maxdigit(int num){
  if(num<10) return num;
  int n=(int)log10(num)+1;
  int left=maxdigit(num/(int)pow(10,n/2));
  int right=maxdigit(num%(int)pow(10,n/2));
  return left>right?left:right;
}

int maxdigit2(string num,int low,int high){
  if(low==high) return num[low]-'0';
  int mid=(low+high)/2;
  int left=maxdigit2(num,low,mid);
  int right=maxdigit2(num,mid+1,high);
  return max(left,right);
}

int main(){
  int num;
  cin>>num;
  int maxd=maxdigit(num);
  int maxd2=maxdigit2(to_string(num),0,to_string(num).length());
  if(maxd<8){
    cout<<"Invalid Transaction: "<<maxd<<endl;
  }else{
    cout<<maxd<<endl;
  }
  cout<<maxd2<<endl;
  return 0;
}