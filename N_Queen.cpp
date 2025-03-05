// Lecture - 6 : Backtracking

#include<iostream>
using namespace std;

bool isSafe(int row,int col,int n,int board[][20]){
    int duprow=row;
    int dupcol=col;

    while(col>=0 && row>=0){      // CASE 1
        if(board[row][col]==1)
        return false;
        col--;
        row--;
    }
    row=duprow;
    col=dupcol;

    while(col>=0){               // CASE 2
        if(board[row][col]==1)
        return false;
        col--;
    }
    row=duprow;
    col=dupcol;

    while(row<n && col>=0){      // CASE 3
        if(board[row][col]==1)
        return false;
        row++;
        col--;
    }

    return true;                // It is safe to put Queen.
}

void solve(int col,int n,int board[][20]){
    if(col == n){                 // Base case
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,n,board)){
            board[row][col]=1;
            solve(col+1,n,board);
            board[row][col]=0;   // Backtracking
        }
    }
}

int main(){
    int board[20][20]={0};
    int n;
    cout<<"Enter the dimention: ";
    cin>>n;
    solve(0,n,board);
}