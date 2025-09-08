#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Event{
  int id;
  int deadline;
  int profit;
};

vector<int> conquer(vector<Event> &arr){
  sort(arr.begin(),arr.end(),[](auto &a,auto &b){
    return a.profit>b.profit;
  });
  int maxdeadline=0;
  for(int i=0;i<arr.size();i++){
    maxdeadline=max(maxdeadline,arr[i].deadline);
  }
  vector<int> slots(maxdeadline+1,-1);
  for(Event i:arr){
    for(int j=i.deadline;j>=1;j--){
      if(slots[j]==-1){
        slots[j]=i.id;
        break;
      }
    }
  }
  vector<int> result;
  for(int i=1;i<=maxdeadline;i++){
    if(slots[i]!=-1) result.push_back(slots[i]);
  }
  return result;
}

vector<int> divide(vector<Event> &arr,int low,int high){
  if(low>=high){
    vector<Event> s={arr[low]};
    return conquer(s);
  }
  int mid=(low+high)/2;
  vector<int> left=divide(arr,low,mid);
  vector<int> right=divide(arr,mid+1,high);
  vector<Event> merged;
  for(int i=low;i<=high;i++){
    merged.push_back(arr[i]);
  }
  return conquer(merged);
}

int main(){
  int n;
  cin>>n;
  vector<Event> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
  }
  vector<int> sequence=divide(arr,0,n-1);
  for(int i:sequence) cout<<i<<" ";
  cout<<endl;
  return 0;
}