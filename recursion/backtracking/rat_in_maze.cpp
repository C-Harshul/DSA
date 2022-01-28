#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[][10],int i,int j,int m,int n){
     if(i==m && j==n){
         soln[m][n] = 1;
         //Print
         for(int i = 0;i<=m; ++i){
             for(int j = 0;j<=n;++j){
                 cout<<soln[i][j]<<" ";
             }
             cout<<endl;
         }
         cout<<endl;
         return true;
     }
     //Rat should be inside the grid;
     if(i>m || j>n){
         return false;
     }
     //The path should not be blocked
     if(maze[i][j] == 'X'){
         return false;
     }
     // Assuming solution exists through current cell
    soln[i][j] = 1;
    bool rightSuccess = ratInMaze(maze,soln,i+1,j,m,n);
    bool downSuccess = ratInMaze(maze,soln,i,j+1,m,n);
    //Backtracking 
    soln[i][j] = 0;
    if(rightSuccess || downSuccess) {
        return true;
    }
    return false;
}

int main(){
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"
    };
    int soln[10][10] = {0};
    ratInMaze(maze,soln,0,0,3,3);
    return 0;
}