#include <iostream>
#include <string.h>

using namespace std;

void balancedBracket(int o, int c, char *s, int n, int i = 0)
{

    if (i == n)
    {
        s[i] = '\0';
        cout << s << endl;
        return;
    }
    if (o < c)
    {
        if (c > 0) 
        {

            s[i] = ')';
            balancedBracket(o, c - 1, s, n, i + 1);
        }
        if (o > 0)
        {

            s[i] = '(';
            balancedBracket(o - 1, c, s, n, i + 1);
        }
    }
    else
    {
        if (o > 0)
        {

            s[i] = '(';
            balancedBracket(o-1, c, s, n, i + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    char s[10000];
    balancedBracket(n, n, s, 2 * n);
    return 0;
}