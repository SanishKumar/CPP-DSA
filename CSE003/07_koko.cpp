#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &piles, int h, int speed)
    {
        long long int hours = 0;
        for (int x : piles)
        {
            hours += x / speed;
            if (x % speed != 0)
            {
                hours++;
            }
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = 0;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(piles, h, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = solution.minEatingSpeed(piles, h);
    cout << "The minimum eating speed is " << result << endl;

    return 0;
}