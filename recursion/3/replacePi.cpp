#include<iostream>
using namespace std;

void replacePi(char s[ ],int i = 0){
    if(s[i] == '\0' || s[i+1] == '\0'){
        return;
    }
    if(s[i] == 'p' && s[i+1] == 'i'){
        int j = i+2;
        while(s[j] != '\0'){
            ++j;
        }
        while(j>=i+2){
            s[j+2] = s[j];
            --j;
        }
        s[i] = '3';
        s[i+1] = '.';
        s[i+2] = '1';
        s[i+3] = '4';
        replacePi(s,i+1);
    } else {
        replacePi(s,i+1);
    }

}

int main(){
    char a[10000];
    cin>>a;
    replacePi(a);
    cout<<a;
    return 0;
}