#include <iostream>

using namespace std;

int main()
{
    char str[100];
    int units;
    float bill,multiplier;
    cin>>str;
    cin>>units;
    if(units<=99)
      multiplier = 0.2;
    else if(units>=100 && units<200)
      multiplier = 0.5;
    else if(units>=200 && units<300)
      multiplier = 0.8;
    else if(units>=300)
      multiplier = 1;

    bill = multiplier*units;
    
    if(bill>100)
    bill =  bill + 0.1*bill;
    if(bill<25) 
    cout<<"Min bill is 25";
    else 
    cout<<bill;
    return 0;
}