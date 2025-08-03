#include<iostream>
#include<cmath>
#include<chrono>
using namespace std;
using namespace std::chrono; 

void findMaxDigit(int num,int *maxi){
    if(num==0){
        return;
    }
    if(num%10>*maxi) *maxi=num%10;
    int digits=(int)log10(num)+1;
    findMaxDigit(num/(int)pow(10,(int)(digits/2)+(digits%2)),maxi);
    findMaxDigit(num%(int)pow(10,(int)digits/2),maxi);
}
 
int main(){
    int num;
    cin>>num;
    int maxi=0;
    auto start=high_resolution_clock::now();
    findMaxDigit(num,&maxi);
    auto end=high_resolution_clock::now();
    if(maxi>=8) cout<<"Valid: "<<maxi<<endl;
    else cout<<"Invalid: "<<maxi<<endl;
    cout<<"Time taken to find Max Digit>Threshold: "<<duration_cast<microseconds>(end-start).count()<<" microseconds"<<endl;
    return 0;
}