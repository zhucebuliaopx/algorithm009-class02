/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, 0);
        unordered_map<int, int> memo;
        for (int i = 0; i < nums.size(); i++){
            if (m.count(target-nums[i]) > 0){
                return {m[target-nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return result;
    }
};
/*
时间复杂度O(n):遍历一遍数组，每次map中取值为O(1)
空间复杂度O(n):主要取决于map的内存，最多存储n个
*/
// @lc code=end

