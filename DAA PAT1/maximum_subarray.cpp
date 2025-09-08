#include<iostream>
#include<vector>
using namespace std;

class Res{
  public:
  int cost;
  int startidx;
  int endidx;
};

Res maximum_crosssum(vector<int> arr, int low,int mid,int high){
  int leftidx=0,leftsum=INT_MIN,rightidx=0,rightsum=INT_MIN;
  int sum=0;
  for(int i=mid;i>=low;i--){
    sum+=arr[i];
    if(sum>leftsum){
      leftsum=sum;
      leftidx=i;
    }
  }
  sum=0;
  for(int i=mid+1;i<=high;i++){
    sum+=arr[i];
    if(sum>rightsum){
      rightsum=sum;
      rightidx=i;
    }
  }
  return {leftsum+rightsum,leftidx,rightidx};
}

Res maximum_subarray(vector<int> arr,int low,int high){
  if(low==high) return {arr[low],low,high};
  int mid=(low+high)/2;
  Res left=maximum_subarray(arr,low,mid);
  Res right=maximum_subarray(arr,mid+1,high);
  Res cross=maximum_crosssum(arr,low,mid,high);
  if(left.cost>right.cost && left.cost>cross.cost) return left;
  else if(right.cost>left.cost && right.cost>cross.cost) return right;
  return cross;
}

int main(){
  vector<int> arr={10,- 20, 5, 30, -25, 10, 5, 40, -50};
  Res result=maximum_subarray(arr,0,arr.size()-1);
  cout<<"Maximum value: "<<result.cost<<endl;
  for(int i=result.startidx;i<=result.endidx;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}