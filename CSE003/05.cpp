// 74. Search a 2D Matrix

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int N = matrix.size();
        int i = 0;
        int M = matrix[i].size();
        int j = (N * M) - 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (matrix[mid / M][mid % M] == target)
            {
                return true;
            }
            else
            {
                if (matrix[mid / M][mid % M] < target)
                {
                    i = mid + 1;
                }
                else
                {
                    j = mid - 1;
                }
            }
        }
        return false;
    }
};
