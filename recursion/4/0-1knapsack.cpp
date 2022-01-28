#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<pair<int, int>> v, int n, int cap)
{

    if (n < 0)
    {
        return 0;
    }
    int possibility = 0;
    if (v[n].second < cap)
    {
        possibility = max(maxProfit(v, n - 1, cap - v[n].second) + v[n].first, maxProfit(v, n - 1, cap));
    }
    else
    {
        possibility = maxProfit(v, n - 1, cap);
    }

    return possibility;
}

int main()
{
    vector<pair<int, int>> vec;
    vec.reserve(1000);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int val, weight;
        cin >> val >> weight;
        vec.push_back(make_pair(val, weight));
    }

    int capacity;
    cin >> capacity;
    cout << maxProfit(vec, n - 1, capacity);
    return 0;
}
