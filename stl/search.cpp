#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
     
    vector<int> c{1,2,3,4};
    int a[] ={1,2,3,4};

    auto add = find(c.begin(),c.end(),2);
    int index = add - c.begin();
    
    if(index == 4)
    cout<<"Not found";
    else
    cout<<index;

    return 0;
}