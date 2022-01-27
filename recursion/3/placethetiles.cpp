#include<iostream>
using namespace std;

int getNoOfWays(int n){
    // Base case
    if(n<=3){
        return 1;
    }   
    // Recursive case
    return getNoOfWays(n-1) + getNoOfWays(n-4);
}
int main(){
    int n;
    cin>>n;
    cout<<getNoOfWays(n);
    return 0;
}