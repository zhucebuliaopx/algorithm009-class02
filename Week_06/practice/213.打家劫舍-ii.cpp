/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp1(n+1), dp2(n+1);
        for (int i = 2; i < n+1; i++) {
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i-2]);
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i-1]);
        }
        return max(dp1[n], dp2[n]);
    }
};
// @lc code=end

