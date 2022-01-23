#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;


int main(){
    string a = "101010",b = "11100";
    int i = a.length()-1,j = b.length() - 1;
    int carry = 0;
    string ans;
    while(i>=0 || j>=0 || carry){
            if(i>=0){
                if(a[i] == '1'){
                    carry++;
                }
                i--;
            }
            if(j>=0){
                if(b[j] == '1'){
                    carry++;
                }
                j--;
            }
            
            ans += (carry%2 + '0');
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}