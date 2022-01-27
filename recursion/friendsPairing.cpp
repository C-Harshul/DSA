#include<iostream>
using namespace std;

int fact(int n){
    if(n <= 1){
        return 1;
    }
    else 
    return n*fact(n-1);
}

int noOfWays(int n) {
    
    if(n < 0){
        return 0;
    }
    if(n == 0)
    return 1;

    return noOfWays(n-1) + (n-1)* noOfWays(n-2);
}

int main() {
    int n;
    cin>>n;
    noOfWays(n);

    return 0;
}