#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int ranks[],int p,int c,int mins){
   int pPos = 0;
   for(int i = 0;i<c;++i){
       int time = 0;
       for(int j = 1;j<=p;++j){
         time = time + j*ranks[i];
         if(time<=mins)
         pPos++;
         else
         break;
       }
   }
   if(pPos>=p)
   return true;
   else 
   return false;
}

int main() {
    int t,anss[100000];
    cin>>t;
    for(int i =0;i<t;++i){
        int p,c,cook_ranks[50];
        cin>>p;
        cin>>c;
        for(int j = 0;j<c;++j){
          cin>>cook_ranks[j];
        }
        sort(cook_ranks,cook_ranks+c);
        int s = cook_ranks[0],e = 0;
        for(int k = 1;k<=p;++k){
          e = e + k*cook_ranks[c-1];
        }
        int ans = e;
        while(s<=e){
            
            int mid = (s+e)/2;
            if(isPossible(cook_ranks,p,c,mid)){
                ans = mid;
                e = mid - 1; 
            } else {
                s = mid + 1;
            }
               
        }
       anss[i] = ans;
    } 
    for(int i = 0;i<t;++i){
        cout<<anss[i]<<endl;
    }
    return 0;

}