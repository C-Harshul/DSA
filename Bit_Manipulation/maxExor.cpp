#include<iostream>
using namespace std;

int maxxor (int x,int y){
    int maxExor = 0,n=2;
	for(int i = x;i<=y;++i) {
		for(int j = i+1;j<=y;++j) {
			maxExor = max(maxExor,i^j);
		}
	}

	return maxExor;
}
int main () {
	int x,y;
	cin>>x>>y;
	int maxExor = maxxor(x,y);
	cout<<maxExor;
	return 0;
}