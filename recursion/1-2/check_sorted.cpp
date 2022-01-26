#include<iostream>
using namespace std;
bool isSorted(int a[],int n){
    if(n == 0 || n == 1){
        return true;
    }
    if(a[0]<a[1] && isSorted(a+1,n-1))
    return true;
    else
    return false;
}
int main() {
    int arr[] = {1,2,11,4,5};
    int n = sizeof(arr)/sizeof(int);
    cout<<isSorted(arr,n);
    return 0;
}