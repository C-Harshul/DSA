#include<iostream>
using namespace std;

int countBinaryString (int n,int i = 0){

    n -= i;
   
    if(n == 1){
        return 2;
    }
    if(n == 0){
        return 1;
    }

    return countBinaryString(n-1,1) + countBinaryString(n-1,0);

}

int main(){
    int n;
    cin>>n;
    cout<<countBinaryString(n);
    return 0;
}
