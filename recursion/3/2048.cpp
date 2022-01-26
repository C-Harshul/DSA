#include <iostream>
using namespace std;

string spellings[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printSpellings(int n)
{

    int num = n % 10;
    if (n == 0)
    {
        return;
    }
    else
    {

        printSpellings(n / 10);

        cout << spellings[num] << " ";
    }
    return;
}

int main()
{

    int n;
    cin >> n;
    printSpellings(n);
}