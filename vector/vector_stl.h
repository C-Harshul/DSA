template<typename T>
class Vector {
  int cs;
  int ms;
  T *arr;
  public: 
  Vector() {
      cs = 0;
      ms = 1;
      arr = new int[ms]; // Points to the last element
  } 
  void push_back(const T d) {
    if(cs == ms) {
        int *oldArr = arr;
        arr = new int [2*ms]; // Finds new space with twice the space
        ms = 2*ms;
        // Copy the existing elements to the new memory location
        for(int i = 0; i<cs;++i){
            arr[i] = oldArr[i];
        } 
        // Clear the old memory space
        delete [] oldArr;
    }
    arr[cs] = d;
    cs++;
  }
  void pop_back() {
      cs--;
  }
  int size() {
      return cs;
  }
  int capacity() {
      return ms;
  }
  //Operator overloading to return the element at index
  int operator[] (const int i) {
      return arr[i];
  } 
};