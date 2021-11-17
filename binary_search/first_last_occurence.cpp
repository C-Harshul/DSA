#include<iostream>

using namespace std;

int first_occurence(int a[],int n,int key){
   int start = 0;
   int end = n-1;
   int ans = -1;
   while(start<=end){
       int mid = (start+end)/2;
       if(a[mid]==key){
           ans=mid;
           end-=1;
       }
       else if(a[mid]>key){
           end-=1;
       } else{
           start+=1;
       }
   }
   return ans;
}

int last_occurence(int a[],int n,int key){
   int start = 0;
   int end = n-1;
   int ans = -1;
   while(start<=end){
       int mid = (start+end)/2;
       if(a[mid]==key){
           ans=mid;
           start+=1;
       }
       else if(a[mid]>key){
           end-=1;
       } else{
           start+=1;
       }
   }
   return ans;
}


int main(){
    int arr []  = {1,2,3,4,5,8,8,8,8,10,12,15,20};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    int pos = first_occurence(arr,n,key);
    int pos2 = last_occurence(arr,n,key);
    cout<<"First occurence at :"<<pos<<endl<<"Last occurence at:"<<pos2;
    return 0; 
}