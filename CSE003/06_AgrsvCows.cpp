#include <vector>
#include <algorithm>

class Solution {
public:
    bool canPlaceCows(const std::vector<int>& stalls, int n, int k, int mid) {
        int count = 1;
        int lastPosition = stalls[0];
        
        for (int i = 1; i < n; ++i) {
            if (stalls[i] - lastPosition >= mid) {
                count++;
                lastPosition = stalls[i];
                if (count == k) {
                    return true;
                }
            }
        }
        return false;
    }

    int solve(int n, int k, std::vector<int>& stalls) {
        std::sort(stalls.begin(), stalls.end());
        
        int left = 1;
        int right = stalls[n - 1] - stalls[0];
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canPlaceCows(stalls, n, k, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
