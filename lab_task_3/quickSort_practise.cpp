#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){

    int pivot = e;
    int i = s;
    for(int j = s;j<=e-1;++j){
        if(arr[j]<arr[pivot]){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[e],arr[i]);
    return i;
}

void quickSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int q = partition(arr,s,e);
    quickSort(arr,s,q-1);
    quickSort(arr,q+1,e);
}

int main(){
    int arr[1000];
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        cin>>arr[i];
    }
    quickSort(arr,0,n-1);
    for(int i = 0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return 0;
}