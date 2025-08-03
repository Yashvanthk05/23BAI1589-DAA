#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

int scalerAddCount=0,scalerMulCount=0;

vector<vector<int>> add(vector<vector<int>> A,vector<vector<int>> B){
  int n=A.size();
  vector<vector<int>> C(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      C[i][j]=A[i][j]+B[i][j];
      scalerAddCount++;
    }
  }
  return C;
}

vector<vector<int>> Matrix_Multiplication(vector<vector<int>> A,vector<vector<int>> B){
  int n=A.size();
  if(n==1){
    scalerMulCount++;
    return {{A[0][0] * B[0][0]}};
  }

  vector<vector<int>> C(n,vector<int>(n,0));
  int mid=n/2;
  vector<vector<int>> A11(mid,vector<int>(mid)),A12(mid,vector<int>(mid)),A21(mid,vector<int>(mid)),A22(mid,vector<int>(mid));
  vector<vector<int>> B11(mid,vector<int>(mid)),B12(mid,vector<int>(mid)),B21(mid,vector<int>(mid)),B22(mid,vector<int>(mid));

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

  vector<vector<int>> C11=add(Matrix_Multiplication(A11,B11),Matrix_Multiplication(A12,B21));
  vector<vector<int>> C12=add(Matrix_Multiplication(A11,B12),Matrix_Multiplication(A12,B22));
  vector<vector<int>> C21=add(Matrix_Multiplication(A21,B11),Matrix_Multiplication(A22,B21));
  vector<vector<int>> C22=add(Matrix_Multiplication(A21,B12),Matrix_Multiplication(A22,B22));

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
  int n;
  cin>>n;
  vector<vector<int>> A(n,vector<int>(n)),B(n,vector<int>(n));
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
  auto start=high_resolution_clock::now();
  vector<vector<int>> C=Matrix_Multiplication(A,B);
  auto end=high_resolution_clock::now();
  cout<<"Result after Matrix Multiplication:"<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<C[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"Number of Scaler Multiplications: "<<scalerMulCount<<endl;
  cout<<"Number of Scaler Additions: "<<scalerAddCount<<endl;
  cout<<"Time taken to Complete Matrix Multiplication: "<<duration_cast<microseconds>(end-start).count()<<" microseconds"<<endl;
  return 0;
}