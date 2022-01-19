#include <iostream>
#include <vector>
using namespace std;
void getPrimeFactors(int n)
{

    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; ++i)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        factors.push_back(make_pair(i, count));
    }
    if (n != 1)
    {
        factors.push_back(make_pair(n, 1));
    }
    for (auto p : factors)
    {
        cout << p.first << "^" << p.second << "*";
    }
}

int main()
{
    int n;
    cin >> n;
    getPrimeFactors(n);
    return 0;
}