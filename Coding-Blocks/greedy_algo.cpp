#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t,sumt[50];
	
	cin>>t;
	for(int i =0;i<t;++i){
		int n,start[10000],end[10000];
		cin>>n;
		for(int j = 0;j<n;++j){
			cin>>start[j];
			cin>>end[j];

		}
		
      int sum = 0 ,position = 0,curr_start=0,curr_end=0,start_size = n,end_size=n;
	   
	  while(start_size>0 && end_size>0){
  
       int min_end_index = min_element(end,end+end_size)-end;
       //cout<<min_end_index<<endl;
       if(start[min_end_index] >= curr_start){
		   curr_start = end[min_end_index];
		   sum++;
	   }  

       for(int i = min_end_index;i<start_size;++i){
			   start[i] = start[i+1];
		   }
		   start_size--;
		   for(int i = min_end_index;i<end_size;++i){
			   end[i] = end[i+1];
		   }
		   end_size--;
		   
	   
       
	  }
	  sumt[i] = sum;
	}
    for(int g = 0;g<t;++g){
        cout<<sumt[g]<<endl;
    }
	return 0;
}