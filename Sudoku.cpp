#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row,int col,int num,int board[4][4]){
    for(int i=0;i<4;i++){
        if(board[row][i]==num)    // Same row checking
        return false;
        if(board[i][col]==num)    // same col checking
        return false;
    }
    
    int rowstart = row - row%2;
    int colstart = col - col%2;
    int last1=rowstart+2;
    int last2=colstart+2;
    for(int p=rowstart;p<last1;p++){    // Box property
         for(int q=colstart;q<last2;q++){
            if(board[p][q]==num)
            return false;
         }
    }
    return true;
}

bool solve(int row,int col,int board[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==0){
                for(int num=1;num<=4;num++){
                    if(isSafe(i,j,num,board)){
                        board[i][j]=num;
                        bool kyaanswerdoge;
                        kyaanswerdoge = solve(i+1,j,board);
                        if(kyaanswerdoge)
                        return true;
                        else
                        board[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    int board[4][4]={{1,0,0,0},
                     {0,2,0,0},
                     {0,0,4,0},
                     {0,0,0,3}};
    if(solve(0,0,board)){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    cout<<"The given Sudoku can't be solved";
}