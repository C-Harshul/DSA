#include <iostream>
#include<set>
#include<string>
using namespace std;

void permutations(char *s,set<string> &sunique, char *out, int n, int i = 0)
{
    if (i == n)
    {
        //cout << out << endl;
        string o(out);
        sunique.insert(o);
        return;
    }
    for (int k = i; s[k] != '\0'; ++k)
    {
        out[i] = s[k];
        swap(s[k], s[i]);
        permutations(s,sunique,out, n, i + 1);
        //backtracking
        swap(s[k], s[i]);
    }
}
int main()
{
    char s[] = "abb";
    char out[1000];
    int n = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        ++n;
    }
    set<string> sunique;
    permutations(s,sunique, out, n);
    for(auto str:sunique){
        cout<<str<<endl;
    }
    return 0;
}