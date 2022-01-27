#include <iostream>
using namespace std;

int noOfWays(int n, int k)
{

    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        ans += noOfWays(n-i,k);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n>>k;

    cout << noOfWays(n, k);
    return 0;
}