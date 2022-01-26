#include<iostream>
using namespace std;

int strintoInt(string s,int n,int i = 1){
    int ans = 0;
    if(n == 0){
        ans += (i * (s[n]-'0'));
        return ans;
    }
    ans = strintoInt(s,n-1,i*10);
    ans += (i * (s[n]-'0'));
    return ans;
}

int main(){
    string s = "74568";
    
    int n = s.length();
    cout<<strintoInt(s,n-1);
    return 0;

}