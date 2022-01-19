#include<iostream>
using namespace std;

void primeSieve(int *a) {

	for(long i = 3;i<=1000000;i+=2) {
		a[i] = 1;
	}
	for(long i = 3;i<=1000000;i+=2) {
		if(a[i] == 1) {
			for(long j = i*i;j<=1000000;j+=i){
				a[j] = 0;
			}
		}
	}
	a[0]=a[1] = 0;
	a[2] = 1;
}

int main() {
	int arr[1000000] = {0};
	primeSieve(arr);
	
	int t;
	cin>>t;
	while(t--) {
		int n,count = 1;
		cin>>n;
		for(int i = 3;count<=n;i+=2) {
			if(arr[i] == 1) 
			count++;
			if(count == n){
				cout<<i<<endl;
				break;
			}

		}
	}
	return 0;
}