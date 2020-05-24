/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int cur = m+n-1;
        while ( p1>=0 && p2>=0 ) {
            nums1[cur--] = nums1[p1] > nums2[p2] ? nums1[p1--]: nums2[p2--];
        }
        
        for (int i =p1+1; i<= p2; i++) {  // 将剩余的nums填充到nums1
            nums1[i] = nums2[i];
        }
    }
};
// @lc code=end

