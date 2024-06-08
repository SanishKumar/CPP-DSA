// 523. Continuous Subarray Sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> remainderMap;
        int cumulativeSum = 0;
        remainderMap[0] = -1;
        for (int i = 0; i < n; i++) {
            cumulativeSum += nums[i];
            int remainder = k == 0 ? cumulativeSum : cumulativeSum % k;
            if (remainderMap.count(remainder)) {
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        return false;
    }
};