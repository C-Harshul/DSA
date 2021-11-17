#include<iostream>
#include<vector>

using namespace std;

int main() { 

    vector <int> d {1,2,3,4};

    //Push
    d.push_back(66); // Pushes the elelment to the endof the vector --> O(1)
     
    //Pop
    d.pop_back(); // Pops the last element from the vector --> O(1)
    
    //Insert 
    d.insert(d.begin() + 3,4,100);// Insert 4 elements(100) from index 3 --> O(n) Here O(4)
 
    //Erase elements
    
    d.erase(d.begin()+2); // Erase the element at index of 2 
    d.erase(d.begin()+1,d.begin()+5);// Erases elements from the first param till right before the second param
    
    //Resize the vector (Shrinking operations are avoided generally)
    //If size is increased more memory is allocated. While shrinking the size capacity remains the same but the size is reduced the the mentioned value.
    
    d.resize(11);

    //Remove all the elements
    d.clear(); // Doesn't unallocate the memory --> capacity remains the same
    
    //Check if the vector is empty
    if(d.empty()){
        cout<<"Empty"<<endl;
    }

    d.push_back(112);
    d.push_back(33);

    //Get the front most element
    cout<<d.front()<<endl;
    //Get the last element of the vector
    cout<<d.back()<<endl;

    return 0;
}