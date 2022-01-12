#include<iostream>

using namespace std;

int main() {
    int a,n;
    cin>>a;
    cin>>n;
    int exp = 1,currentprod = a;
    int temp = n;
    while(temp>0) {
       if(temp&1 == 1) {
           exp = exp*currentprod;
       }
       currentprod *= currentprod;
       temp = temp>>1;
    }

    cout<<exp;
    return 0;
}
