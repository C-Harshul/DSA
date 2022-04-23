#include <iostream>
using namespace std;
void heapify(int a[], int n, int i)
{
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right; 
    if (largest != i)
    {
        swap(a[i],a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0],a[i]);
        heapify(a, i, 0);
    }
} 
void printArr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[1000];
    int n; 
    
    // Get the number of elements in array 
    cout<<"Enter the number elements you want to add to array : ";
    cin>>n;
    // Take the input for the array
    for(int i = 0;i<n;++i){
       cout<<"Enter element "<<i + 1<<" : ";
        cin>>a[i];
    }
    cout << "Before sorting array elements are - \n";
    printArr(a, n);
    heapSort(a, n);
    cout << "\nAfter sorting array elements are - \n";
    printArr(a, n);
    return 0;
}