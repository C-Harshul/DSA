#include<iostream>
using namespace std;
int main() {
	unsigned long long a,b,c,prod,ans = 1;
	cin>>a>>b>>c;
	prod = a;
	prod%=c;
	while(b>0) {
		if(b&1 == 1){
			ans = prod*ans;
		}
		
			ans%=c;
		
		prod = prod * prod;
		prod%=c;
		b = b>>1;
	}
	ans = ans%c;
	cout<<ans;

	return 0;
}