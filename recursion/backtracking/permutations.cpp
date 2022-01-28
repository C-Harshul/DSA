#include <iostream>
#include <vector>
using namespace std;

void permutations(char *s, char *out, int n, int i = 0)
{
    if (i == n)
    {
        cout << out << endl;
        return;
    }
    for (int k = i; s[k] != '\0'; ++k)
    {
        out[i] = s[k];
        swap(s[k], s[i]);
        permutations(s, out, n, i + 1);
        //backtracking
        swap(s[k], s[i]);
    }
}
int main()
{
    char s[] = "abcd";
    char out[1000];
    vector<char> track;
    int n = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        ++n;
    }
    permutations(s, out, n);
    return 0;
}