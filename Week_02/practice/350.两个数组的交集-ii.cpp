/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> memo;
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            memo[nums1[i]]++;
        }

        for (int i = 0; i < nums2.size(); i++){
            if (memo[nums2[i]] > 0) {
                result.push_back(nums2[i]);
            }
            memo[nums2[i]]--;
        }
        return result;
    }
};
// @lc code=end

