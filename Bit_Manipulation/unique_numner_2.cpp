#include<iostream>
using namespace std;

int main(){

    int n, exor = 0,in[100000];
    cin>>n;
    int no;
    for(int i = 0;i<n;++i){
        cin>>no;
        in[i] = no;
        exor = exor^no; 
    } 
    int temp = exor,pos=0,it=0;

    while((temp&1) == 0){
     pos++;
     temp = temp>>1;
    
    }
    int x=0;
    int y = 0;
    int mask = 1<<pos;
    for(int i = 0;i<n;++i){
        if((in[i]&mask)>0){
            x = x^in[i];
        }
    }
    y = exor^x;
    cout<<"First:"<<min(x,y)<<endl<<"Second:"<<max(x,y);    
    return 0;
}
