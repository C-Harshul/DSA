#include <iostream>
using namespace std;

int firstOcc(int a[], int n, int key)
{

    if (n == 0)
    {
        return -1;
    }
    if(a[0] == key){
        return 0;
    }
    int i = firstOcc(a + 1, n - 1, key);
    if (i == -1)
        return -1;

    return i+1;
}

int main()
{
    int a[] = {3, 1, 4, 5, 6, 3, 4, 6};
    int key;
    cin >> key;
    int n = sizeof(a) / sizeof(int);
    int val = firstOcc(a, n, key);
    cout << val;
}