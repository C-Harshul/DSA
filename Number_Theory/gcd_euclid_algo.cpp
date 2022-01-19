#include<iostream>
using namespace std;

int gcd(int a,int b){
    
    return (a==0)?b:gcd(b%a,a);
}

int main() {
    int a,b;
    cin>>a>>b;
    int x = gcd(a,b);
    cout<<x;
    return 0;
}