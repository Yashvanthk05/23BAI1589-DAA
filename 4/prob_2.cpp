#include<iostream>
#include<vector>
#include<chrono>
using namespace std::chrono;
using namespace std;

void maxProfit(vector<int> &arr,int low,int high,vector<int> &maxp){
  if(low==high){
    if(arr[low]>0) maxp.push_back(arr[low]);
    return;
  }
  int mid=(low+high)/2;
  maxProfit(arr,low,mid,maxp);
  maxProfit(arr,mid+1,high,maxp);
}

void solution(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<int> maxp;
  auto start=high_resolution_clock::now();
  maxProfit(arr,0,n-1,maxp);
  auto end=high_resolution_clock::now();
  cout<<"Maximum Total Profits: ";
  for(int i=0;i<maxp.size();i++){
    cout<<maxp[i]<<" ";
  }
  cout<<endl;
  cout<<"Time taken: "<<duration_cast<microseconds>(end-start).count()<<" microseconds"<<endl;
}

int main(){
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    cout<<"Test case "<<i+1<<endl;
    solution();
    cout<<endl;
  }
  return 0;
}