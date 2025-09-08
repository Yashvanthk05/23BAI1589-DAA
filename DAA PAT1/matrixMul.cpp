#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> matrix;

int count_add=0,count_mul=0;

void multiply(matrix A,matrix B,matrix &C,int arow,int acol,int brow,int bcol,int crow,int ccol,int size){
  if(size==1){
    C[crow][ccol]+=A[arow][acol]*B[brow][bcol];
    count_mul++;
    count_add++;
    return;
  }
  int half=size/2;

  multiply(A,B,C,arow,acol,brow,bcol,crow,ccol,half);
  multiply(A,B,C,arow,acol+half,brow+half,bcol,crow,ccol,half);

  multiply(A,B,C,arow,acol,brow,bcol+half,crow,ccol+half,half);
  multiply(A,B,C,arow,acol+half,brow+half,bcol+half,crow,ccol+half,half);

  multiply(A,B,C,arow+half,acol,brow,bcol,crow+half,ccol,half);
  multiply(A,B,C,arow+half,acol+half,brow+half,bcol,crow+half,ccol,half);

  multiply(A,B,C,arow+half,acol,brow,bcol+half,crow+half,ccol+half,half);
  multiply(A,B,C,arow+half,acol+half,brow+half,bcol+half,crow+half,ccol+half,half);
}

int main(){
  int n;
  cin>>n;
  matrix A(n,vector<int>(n,0));
  matrix B(n,vector<int>(n,0));
  matrix C(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>A[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>> B[i][j];
    }
  }
  multiply(A,B,C,0,0,0,0,0,0,n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<C[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"Scalar Multiplications: "<<count_mul<<endl;
  cout<<"Scalar Additions: "<<count_add<<endl;
}