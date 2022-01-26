#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){
    if(n == 1)
    return;
    for(int i = 0;i<n-1;++i){
        if(a[i]>a[i+1])
        swap(a[i],a[i+1]);
    }
    bubbleSort(a,n-1);

}

void bubblerecursive(int a[],int n,int j){
    if (n == 1) {
        return;
    }
    if(j == n-1){
        return bubblerecursive(a,n-1,0);
    }
    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
    bubblerecursive(a,n,j+1);

}

int main(){
    int a[] = {3,1,4,5,2,8,6};
    int n = sizeof(a)/sizeof(int);
    bubblerecursive(a,n,0);
    for(int i = 0;i<n;++i){
        cout<<a[i]<<" ";
    }

    return 0;
}