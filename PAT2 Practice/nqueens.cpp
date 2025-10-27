#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>> &board,int row,int col,int n){
  for(int i=0;i<row;i++){
    if(board[i][col]) return false;
  }
  for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
    if(board[i][j]) return false;
  }
  for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
    if(board[i][j]) return false;
  }
  return true;
}

void solveNQueens(vector<vector<int>> &board,int row,int n,int &count){
  if(row==n){
    count++;
    cout<<"Solution: "<<count<<endl;
    for(int i=0;i<board.size();i++){
      for(int j=0;j<board[i].size();j++){
        cout<<(board[i][j]?"Q":".");
      }
      cout<<endl;
    }
    cout<<endl;
    return;
  }
  for(int col=0;col<n;col++){
    if(isSafe(board,row,col,n)){
      board[row][col]=1;
      solveNQueens(board,row+1,n,count);
      board[row][col]=0;
    }
  }
}

int main(){
  int n;
  cin>>n;
  int count=0;
  vector<vector<int>> board(n,vector<int>(n,0));
  solveNQueens(board,0,n,count);
  cout<<"Total Solutions: "<<count<<endl;
  return 0;
}