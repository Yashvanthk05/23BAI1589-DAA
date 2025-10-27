#include<iostream>
#include<vector>
using namespace std;

bool validQueens(vector<vector<int>> &board,int n){
  vector<int> rowcount(n,0);
  vector<int> colcount(n,0);
  int queencount=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(board[i][j]){
        rowcount[i]++;
        colcount[j]++;
        queencount++;
      }
    }
  }
  if(queencount>n) return false;
  for(int i=0;i<n;i++){
    if(rowcount[i]>1) return false;
    if(colcount[i]>1) return false;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(board[i][j]==1){
        for(int x=i-1,y=j-1;x>=0 && y>=0;x--,y--){
          if(board[x][y]) return false;
        }
        for(int x=i-1,y=j+1;x>=0 && y<n;x--,y++){
          if(board[x][y]) return false;
        }
        for(int x=i+1,y=j+1;x<n && y<n;x++,y++){
          if(board[x][y]) return false;
        }
        for(int x=i+1,y=j-1;x<n && y>=0;x++,y--){
          if(board[x][y]) return false;
        }
      }
    }
  }
  return true;
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>> board(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) cin>>board[i][j];
  }
  cout<<validQueens(board,n);
}