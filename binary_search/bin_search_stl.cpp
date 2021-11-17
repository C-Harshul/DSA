#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{

    int a[] = {1, 2, 2, 2, 2, 2, 2, 5, 10};
    bool present = binary_search(a, a + 9, 2); // CHecking i fthe element is present
    if (present)
    {
        cout << "Present";

        auto it = lower_bound(a, a + 9, 2); // Gives the index of the first occurence of >= k (k = 2)
        cout << endl
             << "Lower bound :" << it - a;
        auto it2 = upper_bound(a, a + 9, 2); // Gives the index of the first occurence of >k (k = 2)
        cout << endl
             << "Upper bound :" << it2 - a;
        cout << endl
             << "Frequency of occurence of 2: " << it2 - it << endl;
    }
    else
    {
        cout << "Not Present";
    }
    return 0;
}