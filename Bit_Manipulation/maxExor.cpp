#include<iostream>
using namespace std;

long maxxor (long x,long y){
    long maxExor = 0,n=2;
	for(long i = x;i<=y;++i) {
		for(long j = i+1;j<=y;++j) {
			maxExor = max(maxExor,i^j);
		}
	}

	return maxExor;
}
int main () {
	long x,y;
	cin>>x>>y;
	long maxExor = maxxor(x,y);
	cout<<maxExor;
	return 0;
}