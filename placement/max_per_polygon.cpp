#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
 
 int n;
 vector<int> x;
 cin>>n;
 for(int i = 0;i<n;++i){
     int no;
     cin>>no;
     x.push_back(no);
 }
 sort(x.begin(),x.end());

 int check = n,f = 0;

 while(x.size()>2){
  int s = 0;
  for(int i = 0;i<check-1;++i){

      s = s+x[i];
  }

  if(s>x[check-1]){
      s = s+x[check-1];
      cout<<s;
      f = 1;
      break;
  }
  else{
      x.pop_back();
      check--;
  } 

 }
 if(f != 1)
 cout<<"-1";
return 0;
}