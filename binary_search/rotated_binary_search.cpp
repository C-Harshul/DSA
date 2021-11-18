#include<iostream>
using namespace std;

int find(int arr[],int n,int key){

    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==key){
          return mid;      
        }
        else if(arr[s]<=arr[mid]){ // Mid in the first part
            if(key>=arr[s] && key<=arr[mid]){ // Search in part 1
                e = mid -1;
            } else {
                s = mid +1;
            }
        } else {
            if(key>=arr[mid] && key<=arr[e]){
             s = mid +1;
            } else {
            e = mid - 1;
            }
        }
    }
}


int main() {
    int n;
    cin>>n;
    int a[1000000];
    for(int i = 0;i<n;++i){
        cin>>a[i];
    }
    int key;
    cin>>key;
    int pos = find(a,n,key);
    cout<<pos;
    return 0;
}