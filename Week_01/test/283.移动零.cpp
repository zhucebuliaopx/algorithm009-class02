/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i =0, last_zero = 0;i<nums.size();i++){
            if (nums[i] != 0){
                std::swap(nums[last_zero++], nums[i]);
            }
        }
    }
};
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int last_zero = 0;
//         for (int i =0;i<nums.size();i++){
//             if (nums[i] != 0){
//                 nums[last_zero++] = nums[i];
//             }
//         }
//         for (int i = last_zero; i<nums.size();i++){
//             nums[i] = 0;
//         }
//     }
// };
// @lc code=end

