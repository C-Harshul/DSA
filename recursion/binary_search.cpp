#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int i, int s = 0)
{
    int mid = (s + n) / 2;
    if(s == n)
    return -1;
    if (a[mid] == i)
        return mid;

    if (a[mid] > i)
    {
        n = mid - 1;
    }
    else if (a[mid] < i)
    {
        s = mid + 1;
    }
    return binarySearch(a, n, i, s);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6,6, 7, 8, 9, 10, 11};
    int i;
    cin >> i;
    int n = sizeof(arr) / sizeof(int) - 1;
    cout << binarySearch(arr, n, i);
    return 0;
}