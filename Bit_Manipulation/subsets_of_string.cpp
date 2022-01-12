#include <iostream>
#include <string.h>
using namespace std;

void filterCharacters(int n, char a[])
{

    int j = 0;
    while (n > 0)
    {
        int last_bit = (n & 1);
        if (last_bit == 1)
        {
            cout << a[j];
        }
        j++;
        n = n >> 1;
    }

    cout << endl;
}

void printSubsets(char a[])
{

    int n = strlen(a);
    for (int i = 0; i < (1 << n); ++i)
    {
        filterCharacters(i, a);
    }
    return;
}

int main()
{

    char a[100];

    cin >> a;
    printSubsets(a);
    return 0;
}
