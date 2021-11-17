#include<iostream>
#include "vector_stl.h"

using namespace std;

int main() {
    
    Vector<int> v;
    v.push_back(11);
    v.push_back(12);
    v.push_back(1);
    v.pop_back();
    v.push_back(18);
    v.push_back(4);
    v.push_back(188);
    
    for(int i = 0;i<v.size();++i){
      cout<<v[i]<<" ";
    }   
    cout<<endl;
    cout<<v.capacity();

    return 0;
}