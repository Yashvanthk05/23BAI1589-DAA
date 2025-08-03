#include<iostream>
#include<vector>
#include<chrono>
using namespace std::chrono;
using namespace std;
 
void merge(vector<int> &arr,int low,int mid,int high){
    int n=high-low+1;
    vector<int> temp;
    int i=low,j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]>=arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=high){
        temp.push_back(arr[j++]);
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
 
void mergeSort(vector<int> &arr,int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
 
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    auto start=high_resolution_clock::now();
    vector<int> fib_seq={1,2};
    while((fib_seq[fib_seq.size()-2]+fib_seq[fib_seq.size()-1])<n){
        fib_seq.push_back(fib_seq[fib_seq.size()-2]+fib_seq[fib_seq.size()-1]);
    }
    vector<int> res;
    for(int i=0;i<fib_seq.size();i++){
        res.push_back(arr[fib_seq[i]]);
    }
    mergeSort(res,0,res.size()-1);
    int idx=0;
    for(int i=0;i<res.size();i++){
        arr[fib_seq[i]]=res[i];
    }
    auto end=high_resolution_clock::now();
    cout<<"Result: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Time taken to Sort elements at fibonacci sequence indices: "<<duration_cast<microseconds>(end-start).count()<<" microseconds"<<endl;
    return 0;
}