/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         std::sort(nums.begin(), nums.end());
//         vector<vector<int>> v;
//         if (nums.size() < 3) return v;
//         for (int i = 0; i < nums.size()-2; i++) {
//             if (nums[i] > 0) break;  //排序之后应该都小于0，才能保证后续和可能为0
//             if (i > 0 && (nums[i] == nums[i-1])) continue;  //避免重复

//             int fp = i + 1;
//             int bp = nums.size()-1;
//             while (fp < bp){
//                 int sum = nums[fp]+nums[bp]+nums[i];
//                 if (sum < 0){
//                     while ( fp < bp && nums[fp] == nums[++fp]);
//                 }else if(sum > 0){
//                     while ( fp < bp && nums[bp] == nums[--bp]);
//                 }else{
//                     v.push_back(vector<int>{nums[i], nums[fp], nums[bp]});
//                     while (fp < bp && nums[fp] == nums[++fp]);
//                     while (fp < bp && nums[bp] == nums[--bp]);
//                 }
//             }
//         }
//         return v;
//     }
// };
// @lc code=end

