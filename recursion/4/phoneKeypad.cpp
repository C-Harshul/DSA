#include<iostream>
using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void generatePossibilities(char num[],char *out,int n,int i = 0,int j = 0){
    if(num[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }
    int index = num[i] - '0';
    string s = keypad[index];
    if(index == 0 || index == 1){
        generatePossibilities(num,out,n,i+1,j);
    }
    for(int k = 0;s[k] != '\0';++k){
        out[j] = s[k];
        generatePossibilities(num,out,n,i+1,j+1);
    }
   return;
}

int main(){
    char num[1000], out[1000];
    cin>>num;
    int n = sizeof(num)/sizeof(char);
    generatePossibilities(num,out,n);
    return 0;
}