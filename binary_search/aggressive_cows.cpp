#include<iostream>
#include<algorithm>
using namespace std;

bool possibleToPlace(int a[],int n,int c,int min){
  
    int count = 1;
    int prev_cow = a[0];//Placing the first cow at the beginning
    for(int i = 0;i<n;++i){
      if(a[i]-prev_cow>=min){
          prev_cow = a[i];
          count++;
          if(count == c) return true;
      }
    } 

    return false;
}

int main() {
    
    int t,ans[100000];
    cin>>t;
 
    for(int i = 0;i<t;++i){
        int n,c;
        cin>>n;
        cin>>c;
        int stall_pos[100000];
        for(int j = 0 ;j<n;++j){
            cin>>stall_pos[j];
        }
        sort(stall_pos,stall_pos+n);
        int s = 0;
        ans[i] = 0;
        int e = stall_pos[n-1]-stall_pos[0];
        while(s<=e){
            //cout<<"Start:"<<s<<", End:"<<e<<endl;
            int mid = (s+e)/2;
            bool canPlace = possibleToPlace(stall_pos,n,c,mid);
            if(canPlace) {
              ans[i] = mid;
              s = mid+1;
            } else {
                e = mid -1;
            }
        }
        

    }

    for(int k = 0;k<t;++k){
        cout<<ans[k]<<endl;
    }
    return 0;
}