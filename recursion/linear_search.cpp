#include<iostream>
using namespace std;

int linearSearch(int a[],int n,int key,int i=0) {
    if(n == 0)
    return -1;
    if(a[i] == key)
    return i;

    return linearSearch(a,n-1,key,i+1);
}

int main() {
    int arr[] = {1,3,2,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    cout<<linearSearch(arr,n,key);
    return 0;
}