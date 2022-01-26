#include<iostream>
using namespace std;

unsigned long fact (unsigned long n) {
    //base case
    if(n==0)
    return 1;

    return n * fact(n-1);
     
}

int main() {
    unsigned long n;
    cin>>n;
    cout<<fact(n);

    return 0;
}