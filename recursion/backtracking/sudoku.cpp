#include<iostream>
using namespace std;

bool isPossible(int board[][10],int n,int row,int col,int num){

    // Check in row on the right;
    for(int j = col;j<n;++j){
        if(board[row][j] == num)
        return false;
    }
    // Check in row on the left
    for(int j = col;j>=0;--j){
        if(board[row][j] == num)
        return false;
    }
    //Check in col bellow
    for(int i = row;i<n;++i){
        if(board[i][col] == num)
        return false;
    }
    //Check in col above
    for(int i = row;i>=0;--i){
        if(board[i][col] == num)
        return false;
    }
    // Check in the box
    int boxCol = (col/3)*3;
    int boxRow = (row/3)*3; 
    for(int i = boxRow;i<boxRow+3;++i){
        for(int j = boxCol;j<boxCol+3;++j){
            if(board[i][j] == num)
            return false;
        }
    }

    return true;
}


bool solveSudoku(int board[][10],int n,int zeros,int I = 0){
    
    if(I == zeros){
        // Print the board
        for(int row = 0;row<n;++row){
            for(int col = 0;col<n;++col){
                cout<<board[row][col]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            if(board[i][j] == 0){
                for(int num = 1;num<=9;++num){
                    if(isPossible(board,n,i,j,num)){
                        board[i][j] = num;
                        bool possible = solveSudoku(board,n,zeros,I+1);
                        if(possible)
                        return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return false;
}

int main(){
    int n,board[10][10],zeros = 0;
    cin>>n;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<n;++j){
            cin>>board[i][j];
            if(board[i][j] == 0)
            zeros++;
        }
    }
    cout<<endl;
    solveSudoku(board,n,zeros);
    return 0;
}