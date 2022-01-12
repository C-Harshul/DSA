#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;
int main() {

    int n,ans = 0,no;
    cin>>n;
    for(int i = 0;i<n;++i){
        cin>>no;
        ans = ans ^ no;
    }
    cout<<ans;


    return 0;
}

// int main() {

//     int n,arr[100],arr2[100],unique = -1;
//     cin>>n;
//     for(int i = 0;i<n;++i){
//         cin>>arr[i];
//     }
//     int f;
//     for(int j = 0;j<n;++j){
//         f = 0;
//         for(int k = 0;k<n;++k){
//             if(arr[k]==arr[j])
//             f++;
//         }
//         if(f == 1)
//         cout<<arr[j]<<endl;
//     }

//     return 0;
// }