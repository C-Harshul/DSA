#include<iostream>
using namespace std;

int merge(int *a,int s,int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int count = 0;
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
        count++;
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
    return count;
}

int inversion_count(int a[],int s,int e){
    if(s>=e){
        return 0;
    }
    int mid = (s+e)/2;
    int x = inversion_count(a,s,mid);
    int y = inversion_count(a,mid+1,e);
    int z = merge(a,s,e);
    return x + y + z;
}

int main() {
    int a[] = {1,5,2,6,3,0};
    int n = sizeof(a)/sizeof(int);
    cout<<inversion_count(a,0,n-1)<<endl;
    return 0;
}