#include<iostream>

using namespace std;
float find_square_root(int n,int p){

 float closest = -1;
 float start = 0;
 float end = n-1;
 while(start<=end) {
     int mid = (start+end)/2;
     if(mid*mid == n){
        return mid;
     } else if(mid*mid > n){
         end = mid -1;
     } else {
         closest = mid;
         start = mid +1;
     }
 }
 // Get the decimal part brute force
 float inc = 0.1;
 for(int times = 1;times<=p;++times){
     while(closest*closest<=n){
         closest = closest+inc;
     }
     closest = closest - inc;
     inc /= 10;

 }
 return closest;
}
int main() {

    int n,p;
    cin>>n;
    cin>>p;
    float root = find_square_root(n,p);
    if(root != -1)
    cout<<root;
    return 0;
}