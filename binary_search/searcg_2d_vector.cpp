#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int s = 0, e = matrix.size() - 1;

    for (auto x : matrix)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    while (s <= e)
    {
        int mid = (s + e) / 2;
        int size = matrix[0].size() - 1;
        if (mid != 0)
        {
            if (target <= matrix[mid][size] && target > matrix[mid - 1][size])
            {
                cout << "Row : " << mid;
                int start = 0, end = size;
                while (start <= end)
                {
                    int Mid = (start + end) / 2;
                    if (matrix[mid][Mid] == target)
                    {
                        cout << "Col :" << Mid << endl;
                        return true;
                    }
                    if (matrix[mid][Mid] > target)
                    {
                        end = Mid - 1;
                    }
                    if (matrix[mid][Mid] < target)
                    {
                        start = Mid + 1;
                    }
                }
                return false;
            }
            else if (target <= matrix[mid - 1][size])
            {
                e = mid - 1;
            }
            else if (target > matrix[mid][size])
            {
                s = mid + 1;
            }
        }
        else
        {
            if (target <= matrix[mid][size])
            {
                int start = 0, end = size;
                while (start <= end)
                {
                    int Mid = (start + end) / 2;
                    if (matrix[mid][Mid] == target)
                    {
                        return true;
                    }
                    if (matrix[mid][Mid] > target)
                    {
                        end = Mid - 1;
                    }
                    if (matrix[mid][Mid] < target)
                    {
                        start = Mid + 1;
                    }
                }
                return false;
            }
            else if (target > matrix[mid][size])
            {
                s = mid + 1;
            }
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> matrix;
    int c, r;
    cin >> c >> r;
    for (int i = 0; i < r; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < c; ++j)
        {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        matrix.push_back(temp);
    }
    int target;
    cout << "Enter the number to be searched :";
    cin >> target;
    cout << searchMatrix(matrix, target);
    return 0;
}