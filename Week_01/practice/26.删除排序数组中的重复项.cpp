/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 0) return 0;
        int length = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[length]) {
                nums[length+1] = nums[i];
                length++;
            }
        }
        return length+1;
    }
};
// @lc code=end

