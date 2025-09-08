#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<int> array;

matrix add(matrix A,matrix B){
  int n=A.size();
  matrix C(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      C[i][j]=A[i][j]+B[i][j];
    }
  }
  return C;
}

matrix multiply(matrix A,matrix B,int n){
  if(n==1){
    return {{A[0][0]*B[0][0]}};
  }
  int half=n/2;
  matrix A11(half,vector<int>(half)),A12(half,vector<int>(half)),A21(half,vector<int>(half)),A22(half,vector<int>(half));
  matrix B11(half,vector<int>(half)),B12(half,vector<int>(half)),B21(half,vector<int>(half)),B22(half,vector<int>(half));
  for(int i=0;i<half;i++){
    for(int j=0;j<half;j++){
      A11[i][j]=A[i][j];
      A12[i][j]=A[i][j+half];
      A21[i][j]=A[i+half][j];
      A22[i][j]=A[i+half][j+half];
      B11[i][j]=B[i][j];
      B12[i][j]=B[i][j+half];
      B21[i][j]=B[i+half][j];
      B22[i][j]=B[i+half][j+half];
    }
  }
  matrix C11=add(multiply(A11,B11,half),multiply(A12,B21,half));
  matrix C12=add(multiply(A11,B12,half),multiply(A12,B22,half));
  matrix C21=add(multiply(A21,B11,half),multiply(A22,B21,half));
  matrix C22=add(multiply(A21,B12,half),multiply(A22,B22,half));
  matrix C(n,vector<int>(n,0));
  for(int i=0;i<half;i++){
    for(int j=0;j<half;j++){
      C[i][j]=C11[i][j];
      C[i][j+half]=C12[i][j];
      C[i+half][j]=C21[i][j];
      C[i+half][j+half]=C22[i][j];
    }
  }
  return C;
}

int main(){
  int n;
  cin>>n;
  matrix A(n,vector<int>(n));
  matrix B(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>A[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>B[i][j];
    }
  }
  matrix C=multiply(A,B,n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<C[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}