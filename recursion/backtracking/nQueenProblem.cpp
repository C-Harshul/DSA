#include<iostream>
using namespace std;



bool isSafe(int board[][10],int i,int j,int n){

    // Check current row
    for(int row = 0;row<i;++row){
        if(board[row][j] == 1){
            return false;
        }
    }

    // Check left diagonal 
    int x = i,y = j;
    while(x>=0 && y>=0){
        if(board[x][y] == 1)
        return false;
        x--;
        y--;
    }
    // Check right diagonal
    x = i;
    y = j;
    while(x>=0 && y<n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}


int solveNQueen(int board[][10],int i,int n,int x){

    if (i == n){
        // Print board
        for(int row = 0;row<n;++row){
            for(int col = 0;col<n;++col){
                if(board[row][col] == 1)
                cout<<"Q"<<" ";
                else
                cout<<"_"<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        ++x;
        return x;
    }

    // Recursive case
    for(int j = 0;j<n;++j){
        if(isSafe(board,i,j,n)){          
            board[i][j] = 1;
            x = solveNQueen(board,i+1,n,x);
            board[i][j] = 0;
        }
    }
    return x;
}

int main() {
    int n;
    int board[10][10] = {0};
    cin>>n;
    cout<<solveNQueen(board,0,n,0);

    return 0;
}