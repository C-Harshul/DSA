//Traverse from both ends
//If the left traversed index is smaller and is smaller than current left max -> water units = leftmax-current. If the current val is greater than leftmax just update leftmax and increment left traversal.
//If the right traversed index is smaller and is smaller than current right max -> water units = rightmax-current. If the current val is greater than rightmax just update leftmax and increment left traversal.


#include<iostream>
using namespace std;
int maxWater_optimized(int arr[], int n)
{
    int water = 0; // To store the final ans

    int left_max = 0;  // Which stores the current max height of the left side
    int right_max = 0; // Which stores the current max height of the right side

    int lo = 0;     // Counter to traverse from the left_side
    int hi = n - 1; // Counter to traverse from the right_side

    while (lo <= hi)
    {

        if (arr[lo] < arr[hi])
        {

            if (arr[lo] > left_max)
            {
                left_max = arr[lo]; // Updating left_max
            }
            else
            {

                water += left_max - arr[lo]; // Calculating the ans
            }
            lo++;
        }
        else
        {

            if (arr[hi] > right_max)
            {
                right_max = arr[hi]; // Updating right_max
            }
            else
            {
                water += right_max - arr[hi]; // Calculating the ans
            }
            hi--;
        }
    }

    return water;
}


int main(){
    int n, v[1000000];
	cin>>n;
	//v.reserve(n);
	for(int u = 0;u<n;++u){
       cin>>v[u];
	}
    int water = maxWater_optimized(v,n);
    cout<<water;
    return 0;
}