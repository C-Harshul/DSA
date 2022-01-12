#include<iostream>

using namespace std;

bool isOdd(int n){
    return(n&1);
}

bool getBit(int n,int i){
    int mask = 1<<i;
    if((mask&n) > 0)
    return 1;
    else 
    return 0;
}

int setBit(int n,int i){
   int mask = 1<<i;
   return (mask|n); 
}

int updateBit(int n,int i,int v){
    int mask = ~(1<<i);
    int cleared_n = n & mask;
    return (cleared_n |(v<<i));
       
}

int clearBit(int n,int i){
     int mask = ~(1<<i);
     return (mask&n);
}

int clearLastIBits(int n,int i){
    int mask = (~(0)<<i);
    return (mask&n);
}

int clearRangeBits(int n,int i,int j){
    int a = (~(0)<<(j+1));
    int b = (1<<i)-1;
    int mask = a|b;
    return (mask&n);
}

int main() {
    cout<<isOdd(3)<<endl;
    cout<<getBit(24,3)<<endl; 
    cout<<setBit(8,4)<<endl;
    cout<<clearBit(9,3)<<endl;
    cout<<updateBit(9,3,0)<<endl;
    cout<<updateBit(9,2,1)<<endl;
    cout<<clearLastIBits(7,2)<<endl;
    cout<<clearRangeBits(15,1,3);
    return 0;
}