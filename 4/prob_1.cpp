#include <bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;
 
struct Res{
    int sum;
    int start;
    int end;
};
 
Res maximum_cross_sum(vector<int> &arr,int low,int mid,int high) {
    int leftsum=0,rightsum=0,left=INT_MIN,right=INT_MIN,leftidx=-1,rightidx=-1;
    for (int i=mid;i>=low;i--) {
        leftsum+=arr[i];
        if ((leftsum>left) || (leftsum==left && mid-i<leftidx-i)) {
            left=leftsum;
            leftidx=i;
        }
    }
    for (int i =mid+1;i<=high;i++) {
        rightsum+=arr[i];
        if ((rightsum>right) || (rightsum==right && mid-i<rightidx-i)) {
            right=rightsum;
            rightidx=i;
        }
    }
    return {left+right,leftidx,rightidx};
}
 
Res maximum_subarray(vector<int> &arr,int low,int high) {
    if (low==high) return {arr[low],low,high};
    int mid=(low + high) / 2;
    Res left=maximum_subarray(arr,low,mid);
    Res right=maximum_subarray(arr,mid+1,high);
    Res cross_sum=maximum_cross_sum(arr,low,mid,high);
    if (left.sum>=right.sum && left.sum>=cross_sum.sum) return left;
    if (right.sum>=left.sum && right.sum>=cross_sum.sum) return right;
    return cross_sum;
}
 
void solution(){
    int n,num;
    cin>>n;
    vector<int> arr;
    for (int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    auto start=high_resolution_clock::now();
    Res res=maximum_subarray(arr,0,n-1);
    auto end=high_resolution_clock::now();
    cout<<"Maximum Sum: "<<res.sum<<endl;
    for (int i=res.start;i<=res.end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Time taken: "<<duration_cast<microseconds>(end-start).count()<<" microseconds"<<endl;
}
 
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        cout<<"Test Case: "<<i+1<<endl;
        solution();
        cout<<endl;
    }
    return 0;
}