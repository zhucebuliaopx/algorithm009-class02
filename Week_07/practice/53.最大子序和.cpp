/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for (int num: nums) {
            if (sum > 0) {
                sum += num;
            }else{
                sum = num;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end

