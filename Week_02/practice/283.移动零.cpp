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
/*
空间复杂度O(1): 常量个数的变量
时间复杂度O(n): 操作总数是非0的个数，虽然也是O(n)，要比不交换的时间复杂度好的多
*/
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

/*
空间复杂度O(1): 常量个数的变量
时间复杂度O(n): 操作总数为n
*/
// @lc code=end

