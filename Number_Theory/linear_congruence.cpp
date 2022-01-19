#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {

	unsigned long int n,a[1000],r[1000];
	cin>>n;
    for(unsigned long int i = 0;i<n;++i){
		cin>>a[i];
	}
	for(unsigned long int i = 0;i<n;++i) {
		cin>>r[i];
	}
	unsigned long int x = *max_element(a, a + n);
    
	  unsigned long int i = 0;
      while(i<n){
		  if(x%a[i]!=r[i]){
			  x++;
              i=-1;
		  }
          ++i;
	  }
    cout<<x;
    // cout<<345%5<<endl<<345%7<<endl<<345%9<<endl<<345%11;
	return 0;
}