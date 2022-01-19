
#include <iostream>
using namespace std;
int main()
{
    int t, steps[100000], x = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        int y = n;
        while (y > 0)
        {
            x = 0;
            while ((1 << (x + 1)) <= y)
            {
                ++x;
            }
            y = y - (1 << x);
            steps[i]++;
        }
    }
    for(int j = 0 ;j<t;++j) {
        cout<<steps[j]<<endl;
    }
    return 0;
}