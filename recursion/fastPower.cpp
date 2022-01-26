#include<iostream>
using namespace std;

int fastPow(int a,int n){
    if(n == 0)
    return 1;
    int ans = fastPow(a,n/2);
    ans*=ans;
    if(n%2 == 1){
        ans = a*ans;
    } 
    return ans;
}

int main() {
    int a,n;
    cin>>a>>n;
    cout<<fastPow(a,n);

    return 0;
}