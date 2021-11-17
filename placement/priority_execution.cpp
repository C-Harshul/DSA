#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,temp[100];
   cin>>n;
   for(int i=0;i<n;++i){
       cin>>temp[i];
   }
  

int t=n;
int sum = 0,k=0;
 while(t>1){
     int max = *max_element(temp, temp + n-k);
     int min = *min_element(temp, temp + n-k);
     
     sum = sum +  max - min;
     //cout<<sum<<endl;
   for(int q=0;q<n-k;++q){
        if(temp[q] == min){
              temp[q] = max-min;
          }
   }
   for(int v=0;v<n-k;++v){
       if(temp[v] == max){
             
              for(int g = v;g<n-k-1;++g){
                  temp[g] =temp[g+1];
              }
              ++k;
           break;  
          }
   }
   
   --t;
   
 }
  cout<<sum;
}