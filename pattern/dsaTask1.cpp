#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    if (n % 2 != 0)
    {
        string last = " @ ";
        for (int i = 0; i <= n / 2; ++i)
        {
            for (int j = n / 2; j >= i; --j)
            {
                cout << "   ";
            }
            for (int k = 0; k < 2 * (i + 1) - 1; ++k)
            {
                if (i % 2 == 0)
                {

                    cout << " @ ";
                    last = " @ ";
                }
                else
                {

                    cout << " # ";
                    last = " # ";
                }
            }
            cout << endl;
        }
        for (int i = 0; i < n / 2; ++i)
        {
            for (int j = 0; j <= i + 1; ++j)
                cout << "   ";
            for (int k = 0; k < (2 * ((n / 2) - i) - 1); ++k)
            {
                if (last == " @ ")
                {
                    if (i % 2 == 0)
                    {

                        cout << " # ";
                    }
                    else
                    {
                        cout << " @ ";
                    }
                }
                else if (last == " # ")
                {
                    if (i % 2 == 0)
                    {

                        cout << " @ ";
                    }
                    else
                    {
                        cout << " # ";
                    }
                }
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Even number should not be entered";
    }
    return 0;
}