#include<iostream>
#include<algorithm>

using namespace std;
int main(){


    int curr[] = {1,2,5,10,20,50,100,200,500,2000};
    int amount,coins = 0;
    cin>>amount;
    int x = sizeof(curr)/sizeof(int);
    while(amount>=1){
        auto divisor = lower_bound(curr,curr+10,amount);
        bool present = binary_search(curr,curr+10,amount);
        if(!present){
           divisor-=1;
        }
        //cout<<*divisor<<endl;
        int num = amount/(*divisor);
        int sub = num*(*divisor);
        cout<<(*divisor)<<" * "<<num<<endl;
        coins += num;
        amount = amount - sub;
    }
    cout<<coins<<endl;
    return 0;
}