#include<iostream>
using namespace std;

int storeOcc(int a[],int i,int n,int key,int *out,int j){
    if(i == n){
        return j;
    }
    if(a[i] == key) {
        out[j] = i;
       return storeOcc(a,i+1,n,key,out,j+1);
    }
    return storeOcc(a,i+1,n,key,out,j);

}

int main(){

    int a[] = {3,1,2,4,5,3,2,4,5,6,6,8,6};
    int out[100];
    int n = sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    int count = storeOcc(a,0,n,key,out,0);
    for(int i = 0;i<count;++i){
        cout<<out[i]<<" ";
    }
    return 0;
}