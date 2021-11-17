#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main(){
 
 int n;
 cin>>n;
 vector<int> a;
 a.reserve(1000000000);
 for(int i = 0;i<n;++i){
     int temp;
     cin>>temp;
     a.push_back(temp);
 }

 int sum = 0;
 while(a.size()>1){
     int max = *max_element(a.begin(),a.end());
     int min = *min_element(a.begin(),a.end());
     sum = sum + max-min;
       for(int j = 0;j<a.size();++j){
         if(a[j] == min)
         a[j] = max - min;
     }
     for(int i=0;i<a.size();++i) {
         if(a[i] == max){
             a.erase(a.begin()+i);
             break;
         }
     }
 }
 cout<<sum;
 return 0;
}
