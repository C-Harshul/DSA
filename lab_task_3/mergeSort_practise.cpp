#include<iostream>
using namespace std;

void merge(int arr[],int s,int e){
    int mid = (s+e)/2;
    int temp[1000];
    int i = s;
    int j = mid+1;
    int k = s;
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k] = arr[i];
            ++i;
            ++k;
        } else if(arr[j]<arr[i]) {
            temp[k] = arr[j];
            ++j;
            ++k;
        }
    }
    while(i<=mid){
        temp[k] = arr[i];
            ++i;
            ++k;
    }
    while(j<=e){
        temp[k] = arr[j];
        ++j;
        ++k;
    }
    for(int i = s;i<=e;++i){
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[],int s,int e){
    if(s>=e)
       return;

    int mid = (s+e)/2;
    mergeSort(arr,s,mid-1);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main(){

    int arr[1000],n;
    cin>>n;
    for(int i = 0;i<n;++i){
        cin>>arr[i];
    }
    for(int i = 0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,0,n-1);
    for(int i = 0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return 0;
}