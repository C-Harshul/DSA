#include<iostream>
#include<vector>

using namespace std;

int main() {
     
    // Create and initialise vectors

    vector<int> a(5,0); // five elements with value 0
    vector<int> b(a.begin(),a.end()); // Copy all the elements from b to a
    vector<int> c{1,2,3,4};

    //Reserve vector space
    c.reserve(1000); // Reserves the space of 1000 for vector c. Doubling happens only after the size reaches 1000
    
    //Iterate over the vector

    for(int i = 0;i<a.size();++i){
        cout<<a[i]<<",";
    }
    cout<<endl;
    for(auto it=b.begin();it!=b.end();it++){
        cout<<*it<<",";
    }
    cout<<endl;
    for(int x:c){
        cout<<x<<",";
    }
    cout<<endl;
   //Taking elements from the user dynamically

   vector<int> v;
   int n;
   cin>>n;
   for(int i =0;i<n;++i){

       int no;
       cin>>no;
       v.push_back(no);//Adds the no to the end of the vector v. Also expands the memory if needed by doubling the memory if required.
   }
   cout<<endl;
   cout<<v.capacity()<<endl;//Gives the current capacity of the array.
   cout<<v.size()<<endl;//Gives the current occupied size of the array.4
    
   for(int x:v){
       cout<<x<<" ";
   }

    return 0;
}