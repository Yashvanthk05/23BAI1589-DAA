#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

const int d = 256;
const int q = 101;

vector<pair<int,int>> Rabin_Karp_Partial(string &T,string &P) {
    int n = T.size();
    int m = P.size();
    vector<pair<int,int>> partialShifts;
    int klimit=ceil(2*m+2)/3;
    int pHash = 0, tHash = 0, h = 1;
    for (int i=0;i<m-1;i++)
        h=(h*d)%q;
    for(int i=0;i<m;i++) {
        pHash=(d*pHash+P[i])%q;
        tHash=(d*tHash+T[i])%q;
    }
    for(int s=0;s<=n-m;s++){
        if(pHash==tHash){
            if(T.substr(s,m)==P){
                cout<<"Fully valid shift at "<<s<<endl;
            }
        }    
        for(int k=m-1;k>=klimit;--k){
            if(s+k<=n && P.substr(0, k)==T.substr(s,k)){
                partialShifts.push_back({s,k});
                break;
            }
        }
        if(s<n-m){
            tHash=(d*(tHash-T[s]*h)+T[s+m])% q;
            if(tHash<0) tHash+=q;
        }
    }
    return partialShifts;
}

int main(){
    string T="abcdeabcfabc";
    string P="abc";
    cout<<"Text = "<<T<<endl;
    cout<<"Pattern = "<<P<<endl;
    vector<pair<int,int>> partials=Rabin_Karp_Partial(T,P);
    cout<<"Partially valid shifts (shift, k): ";
    for(pair<int,int> x: partials){
        cout<<"("<<x.first<<", "<<x.second<<") ";
    }
    cout<<endl;
    return 0;
}
