#include <iostream>
using namespace std;

int lastOccurence(int a[], int key, int n)
{
    if (n == 0)
    {
        return -1;
    }
    int i = lastOccurence(a + 1, key, n - 1);

    if (i == -1)
    {
        if (a[0] == key)
            return 0;
        else 
            return -1;
    } 

    return i + 1;
}

int main()
{
    int a[] = {3, 1, 3, 6, 5, 4, 6, 1, 5};
    int key;
    cin >> key;
    int n = sizeof(a) / sizeof(int);
    cout << lastOccurence(a, key, n);
    return 0;
}