#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Activity{
  int start;
  int finish;
};

int main(){
  int n;
  cin>>n;
  vector<Activity> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i].start>>arr[i].finish;
  sort(arr.begin(),arr.end(),[](Activity a,Activity b){
    return a.finish<b.finish;
  });
  int count=1;
  int last=arr[0].finish;
  for(int i=1;i<n;i++){
    if(last<=arr[i].start){
      count++;
      last=arr[i].finish;
    }
  }
  cout<<count;
  return 0;
}