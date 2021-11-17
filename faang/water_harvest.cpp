#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,sum=0,v[1000000];
	cin>>n;
	//v.reserve(n);
	for(int u = 0;u<n;++u){
       cin>>v[u];
	}
	
	for(int i = 0;i<n;++i){

		int units_above = 0;
        int right_max,left_max; 
        if(i!=n-1)
		right_max = *max_element(v+i+1,v+n);
        else
        right_max = 0;
        if(i!=0)
		left_max = *max_element(v,v+i);
        else
        left_max = 0;

		units_above = std::min(right_max,left_max) -v[i];
		if(units_above<0)
		units_above = 0;
		sum+=units_above;
	}
	cout<<sum;
	return 0;
}