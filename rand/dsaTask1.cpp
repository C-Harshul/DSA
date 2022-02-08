#include <iostream>
using namespace std;
bool isCorrect(string str)
{
    int n = str.length();
 
    int i;
    for (i = 0; i < n; i++)
        if (str[i] != 'a')
            break;
    if (i * 2 != n)
        return false;
 
    int j;
    for (j = i; j < n; j++)
        if (str[j] != 'b')
            return false;
 
    return true;
}
 
int main()
{
    string str;
    cin>>str;
    isCorrect(str) ? cout << "Yes" : cout << "No";
    return 0;
}