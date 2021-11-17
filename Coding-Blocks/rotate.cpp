#include<iostream>
#include<algorithm>
using namespace std;


void rotate_left_45(int a [][1000],int n){
    for(int row = 0;row<n;++row) {
        int start = 0;
        int end_col = n-1;
        while(start<end_col) {
            swap(a[row][start],a[row][end_col]);
            start++;
            end_col--; 
        }
    }
    for(int col = 0;col<n;++col) {
        int start = 0;
        int end_row = n-1;
        while(start<end_row) {
            swap(a[start][col],a[end_row][col]);
            start++;
            end_row--; 
        }
    }
    
    for(int i = 0;i<n;++i) {
        for(int j = 0;j<n;++j){
            if(i<j){
                swap(a[i][j],a[j][i]);
            }
        }
    }
}

void rotate_right_45(int a [][1000],int n){
  
    for(int col = 0;col<n;++col) {
        int start = 0;
        int end_row = n-1;
        while(start<end_row) {
            swap(a[start][col],a[end_row][col]);
            start++;
            end_row--; 
        }
    }
    
    for(int i = 0;i<n;++i) {
        for(int j = 0;j<n;++j){
            if(i<j){
                swap(a[i][j],a[j][i]);
            }
        }
    }
}


void disp (int a[][1000],int n) {
    for(int i = 0;i<n;++i) {
        for(int j = 0;j<n;++j) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int arr[1000][1000];
    int n;
    cout<<"Enter matrix dimension:";
    cin>>n;
    for(int i = 0 ;i<n;++i) {
        for(int j = 0;j<n;++j) {
            cin>>arr[i][j];
        }
    }
    rotate_right_45(arr,n);
    cout<<endl<<"Right rotate"<<endl;
    disp(arr,n);
    rotate_left_45(arr,n);
    cout<<endl<<"Left rotate"<<endl;
    disp(arr,n);
    return 0;
}