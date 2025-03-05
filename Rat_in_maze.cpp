#include<iostream>
using namespace std;

bool isSafe(int row,int col,int n,int maze[][20],int visited[][20]){
    if (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1 && visited[row][col] == 0){
        return true;
    }
    return false; 
}

void solve(int row,int col,int n,int maze[][20],int visited[][20]){
    if(row==n-1 && col==n-1){    // Base case
    visited[row][col]=1;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
       }
       cout<<endl;
       visited[row][col]=0;
       return;
    }
    
    if(isSafe(row+1,col,n,maze,visited)){    // Down
        visited[row][col]=1;
        solve(row+1,col,n,maze,visited);
        visited[row][col]=0;
    }

    if(isSafe(row-1,col,n,maze,visited)){     // Up
        visited[row][col]=1;
        solve(row-1,col,n,maze,visited);
        visited[row][col]=0;
    }

    if(isSafe(row,col+1,n,maze,visited)){     // Right
        visited[row][col]=1;
        solve(row,col+1,n,maze,visited);
        visited[row][col]=0;
    }

    if(isSafe(row,col-1,n,maze,visited)){    // left
        visited[row][col]=1;
        solve(row,col-1,n,maze,visited);
        visited[row][col]=0;
    }
}

int main(){
    int maze[20][20]={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,1},
        {0,1,0,1}
        };
    int visited[20][20]={0};
    int n = 4;
    if(maze[0][0]==0)
    return 0;
    if(maze[n-1][n-1]==0)
    return 0;
    solve(0,0,n,maze,visited);
    return 0;
}