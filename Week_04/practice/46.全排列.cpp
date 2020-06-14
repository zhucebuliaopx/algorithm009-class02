/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        if (size == 0) return result;
        dfs(nums, result, 0, size);
        return result;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &result, int first, int size) {
        if (first == size){
            result.emplace_back(nums);
            return;
        }
        for (int i = first; i < size ; i++){
            swap(nums[i], nums[first]);
            dfs(nums,result, first+1, size);
            swap(nums[i], nums[first]);
        }
    }
};
// @lc code=end

