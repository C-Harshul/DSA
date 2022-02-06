#include<iostream>
using namespace std;

int count = 0;

void getCount(int n,char *s,int i = 0){
	if(i == n){
		// Print the string
		s[i] = '\0';
		cout<<s<<endl;
		return;
	}
	s[i] = 'a';
	getCount(n,s,i+1);

	if(s[i-1] != 'b'){
		s[i] = 'b';
		getCount(n,s,i+1);
	}
	

}

int main() {
	
	char s[1000];

		int n;
		cin>>n;
		getCount(n,s);
	return 0;
}