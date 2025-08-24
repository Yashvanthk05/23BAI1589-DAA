#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutRecTopDown(vector<int> &arr,int c,int cost) {
    if (c==0) return 0;
    int m=INT_MIN;
    for (int i=1;i<=c;i++){
        int v=arr[i-1]+rodCutRecTopDown(arr,c-i,cost);
        if (i!=c) v-=cost;
        m=max(m,v);
    }
    return m;
}

int rodCutMemo(vector<int> &arr,int c,int cost,vector<int> &dp) {
    if(c==0) return 0;
    if (dp[c]!=-1) return dp[c];
    int m=INT_MIN;
    for (int i=1;i<=c;i++){
        int v=arr[i-1]+rodCutMemo(arr,c-i,cost,dp);
        if(i!=c) v-=cost;
        m=max(m, v);
    }
    return dp[c]=m;
}

int rodCutBottomUp(vector<int> &arr,int c,int cost) {
    vector<int> dp(c+1,0);
    vector<int> cut(c+1,0);
    for (int i=1;i<=c;i++) {
        int m=INT_MIN;
        for (int j=1;j<=i;j++) {
            int v=arr[j-1]+dp[i-j];
            if (j!=i) v-=cost;
            if (v>m) {
                m=v;
                cut[i]=j;
            }
        }
        dp[i]=m;
    }

    int t=c;
    cout<<"(Cuts: ";
    while(t>0){
        cout<<cut[t]<<" ";
        t-=cut[t];
    }
    cout<<") ";
    return dp[c];
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i=0;i<n;i++) cin>>arr[i];
    int length,cost;
    cout<<"Rod Length: ";
    cin>>length;
    cout<<"Cutting Cost: ";
    cin>>cost;
    cout<<"Recursive Top-Down Revenue: "<<rodCutRecTopDown(arr,length,cost)<<endl;
    vector<int> dp(length+1,-1);
    cout<<"Memoized Top-Down Revenue: "<<rodCutMemo(arr,length,cost,dp)<<endl;
    cout<<"Extended Bottom-Up Revenue: "<<rodCutBottomUp(arr,length,cost)<<endl;
    return 0;
}