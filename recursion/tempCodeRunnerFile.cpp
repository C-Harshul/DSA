int binarySearch(int a[], int n, int i, int s = 0)
// {
//     int mid = (s + n) / 2;
//     if (a[mid] == i)
//         return mid;
//     else
//     {

//         if (a[mid] > i)
//         {
//             n = mid - 1;
//         }
//         else if (a[mid] < i)
//         {
//             s = mid + 1;
//         }
//         int val = binarySearch(a, n, i, s);
//     }
// }