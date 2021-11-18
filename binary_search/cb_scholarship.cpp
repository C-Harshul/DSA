#include<iostream>

using namespace std;
bool isPossible(long n,long m,long x,long y,long mid){
    long scholars = mid;
    long remaning = n-scholars;
    int required_coupons = scholars*x;
    int available_coupons = m + remaning*y;
    if(required_coupons > available_coupons)
    return false;
    else 
    return true;
}
int main() {
    long N,M,X,Y,ans = 0;
    cin>>N>>M>>X>>Y;
    long s = 0;
    long e = N;
    while(s<=e){
        int mid = (s+e)/2;
        if(isPossible(N,M,X,Y,mid)){
           ans = mid;
           s = mid + 1;
        } else {
           e = mid - 1;
        }
    }
    //cout<<isPossible(N,M,X,Y,10);
    cout<<ans;
    return 0;
}