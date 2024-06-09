#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canCowsBePlaced(int gap, int n, vector<int> &stalls, int k)
    {
        int cows = 1;
        int pos = 0;
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - stalls[pos] >= gap)
            {
                cows++;
                pos = i;
            }
        }
        if (cows >= k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int maxGap = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canCowsBePlaced(mid, n, stalls, k) == true)
            {
                maxGap = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return maxGap;
    }
};
