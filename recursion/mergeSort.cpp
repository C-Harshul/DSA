#include<iostream>
using namespace std;

void merge(int *a,int s,int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[100];
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
        temp[k] = a[i];
        ++i;
        ++k;
    } else if(a[i]>a[j]){
        temp[k] = a[j];
        ++j;
        ++k;
    }
    }
    while(i<=mid){
        temp[k] = a[i];
        ++k; ++i;
    }
    while(j<=e){
        temp[k] = a[j];
        ++k;++j;
    }
    for(int i = s;i<=e; ++i){
        a[i] = temp[i];
    }
}

void mergeSort(int a[],int s,int e){
    if(s == e){
        return;
    }
    //Divide 
    int mid = (s+e)/2;
    // recursively Sort the 2 sub arrays (s till mid and mid+1 till e)
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    // Merge the 2 arrays
    merge(a,s,e);

    return;
}

int main(){
    int a[] = {3,1,5,2,0,9};
    int n = sizeof(a)/sizeof(int);
    mergeSort(a,0,n-1);
    for(int i = 0;i<n; ++i){
        cout<<a[i]<<" ";
    }
    return 0;
}