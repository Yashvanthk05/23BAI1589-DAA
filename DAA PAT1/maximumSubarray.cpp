#include<iostream>
#include<vector>
using namespace std;

struct Res{
  int sum;
  int start;
  int end;
};

Res maxcrosssum(vector<int> arr,int low,int mid,int high){
  int leftsum=INT_MIN,rightsum=INT_MIN,sum=0;
  int leftidx=mid,rightidx=mid+1;
  for(int i=mid;i>=low;i--){
    sum+=arr[i];
    if(sum>leftsum || (sum==leftsum && (mid-i+1)<(mid-leftidx+1))){
      leftsum=sum;
      leftidx=i;
    }
  }
  sum=0;
  for(int i=mid+1;i<=high;i++){
    sum+=arr[i];
    if(sum>rightsum || (sum==rightsum && (mid-i+1)<(mid-rightidx+1))){
      rightsum=sum;
      rightidx=i;
    }
  }
  return {leftsum+rightsum,leftidx,rightidx};
}

Res maxsumsubarray(vector<int> arr,int low,int high){
  if(low==high) return {arr[low],low,high};
  int mid=(low+high)/2;
  Res left=maxsumsubarray(arr,low,mid);
  Res right=maxsumsubarray(arr,mid+1,high);
  Res cross=maxcrosssum(arr,low,mid,high);
  if(left.sum>right.sum && left.sum>cross.sum) return left;
  if(right.sum>left.sum && right.sum>cross.sum) return right;
  return cross;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  Res res=maxsumsubarray(arr,0,n-1);
  cout<<"Maximum Sum Subarray: "<<res.sum<<endl;
  for(int i=res.start;i<=res.end;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}