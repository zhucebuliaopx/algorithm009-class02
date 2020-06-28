/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> result;
        if (size < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size-3;i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j< size-2;j++){
                if (j>i+1 && nums[j] == nums[j-1]) continue;
                int fp = j +1;
                int bp = size -1;
                while (fp <bp) {
                    int sum = nums[i]+nums[j]+nums[fp]+nums[bp];
                    if (sum > target){
                        while (fp <bp && nums[bp] == nums[--bp]);
                    }else if (sum < target){
                        while (fp <bp && nums[fp] == nums[++fp]);
                    }else{
                        result.push_back({nums[i], nums[j],nums[fp],nums[bp]});
                        while (fp <bp && nums[bp] == nums[--bp]);
                        while (fp <bp && nums[fp] == nums[++fp]);
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

