#include <iostream>
#include <vector>
using namespace std;

void primeSieve(int *p)
{

    for (long i = 3; i <= 1000000; i += 2)
    {
        p[i] = 1;
    }
    for (long i = 3; i <= 1000000; i += 2)
    {
        if (p[i] == 1)
        {
            for (long j = i * i; j <= 1000000; j += i)
            {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main()
{
    int n;
    cin >> n;
    int p[1000000] = {0};
    primeSieve(p);
    while (n--)
    {
        int x;
        vector<pair<int, int>> factors;
        cin >> x;
        for (long i = 2; i * i <= x; ++i)
        {
            if (p[i] == 1)
            {
                int count = 0;
                while (x % i == 0)
                {
                    count++;
                    x /= i;
                }
                factors.push_back(make_pair(i, count));
            }
        }
        if (x != 1)
        {
            factors.push_back(make_pair(x, 1));
        }
        int noOfDivisors = 1;
        for (auto p : factors)
        {
            cout << p.first << "^" << p.second << "*";
            noOfDivisors = noOfDivisors * (p.second + 1);
        }
        noOfDivisors*=2;
        cout <<endl<<"Number of divisors :"<< noOfDivisors;
        cout << endl;
    }
    return 0;
}