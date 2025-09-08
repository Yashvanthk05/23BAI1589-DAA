#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> arr;
typedef vector<vector<int>> matrix;

matrix add(matrix A,matrix B){
  int n=A.size();
  matrix C(n,arr(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      C[i][j]=A[i][j]+B[i][j];
    }
  }
  return C;
}

matrix MatrixMul(matrix A,matrix B){
  int n=A.size();
  if(n==1){
    return {{A[0][0]*B[0][0]}};
  }
  int mid=(int)(n/2);
  matrix A11(mid,arr(mid)),A12(mid,arr(mid)),A21(mid,arr(mid)),A22(mid,arr(mid));
  matrix B11(mid,arr(mid)),B12(mid,arr(mid)),B21(mid,arr(mid)),B22(mid,arr(mid));
  for(int i=0;i<mid;i++){
    for(int j=0;j<mid;j++){
      A11[i][j]=A[i][j];
      A12[i][j]=A[i][j+mid];
      A21[i][j]=A[i+mid][j];
      A22[i][j]=A[i+mid][j+mid];
      B11[i][j]=B[i][j];
      B12[i][j]=B[i][j+mid];
      B21[i][j]=B[i+mid][j];
      B22[i][j]=B[i+mid][j+mid];
    }
  }
  matrix C11=add(MatrixMul(A11,B11),MatrixMul(A12,B21));
  matrix C12=add(MatrixMul(A11,B12),MatrixMul(A12,B22));
  matrix C21=add(MatrixMul(A21,B11),MatrixMul(A22,B21));
  matrix C22=add(MatrixMul(A21,B12),MatrixMul(A22,B22));
  
  matrix C(n,arr(n));
  for(int i=0;i<mid;i++){
    for(int j=0;j<mid;j++){
      C[i][j]=C11[i][j];
      C[i][j+mid]=C12[i][j];
      C[i+mid][j]=C21[i][j];
      C[i+mid][j+mid]=C22[i][j];
    }
  }
  return C;
}

int main(){
  matrix A={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  matrix B={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  matrix res=MatrixMul(A,B);
  for(int i=0;i<A.size();i++){
    for(int j=0;j<A.size();j++){
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}