#include<iostream>

using namespace std;
int main() {

    int count[64] ={0};
    int n;
    cin>>n;

    int no;
    for(int i = 0;i<n;++i) {
      cin>>no;
      int x = 0;
      while(no>0) {
        count[x] = count[x] + (no&1); 
        no = no>>1;
        x++; 
      } 
      
    }
    int y = sizeof(count)/sizeof(int);
   int unique_num = 0;
   for(int i = 0;i<y;++i) {
       unique_num = unique_num + (1<<i)*(count[i] % 3); 
   }
   cout<<unique_num;

    return 0;
}