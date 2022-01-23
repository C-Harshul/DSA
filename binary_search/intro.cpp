#include<iostream>
#include<algorithm>

using namespace std;

int binary_search(int arr[],int n,int number) {
    int start = 0;
    int end = n-1;

    while(start<=end){
        //cout<<start<<","<<end<<",";
        int mid = (start + end)/2;
        if(arr[mid] == number) {
            return mid;
        }
        else if(arr[mid]>number){
          end = mid-1;
        } else {
          start = mid+1;
        } 
    }
    if(start>end){
            if(arr[end]<number)
                return start;
            else 
                return end;
        }
    return -1;
}
int main() {
    int arr[1000],n,number;
    cin>>n;
    for(int i = 0;i<n;++i){
        cin>>arr[i];
    }      
  
   
    cin>>number;
    int position = binary_search(arr,n,number);
    cout<<position<<endl;
    return 0;
}