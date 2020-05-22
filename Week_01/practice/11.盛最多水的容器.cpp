/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i = 0, j = height.size()-1; i < j;) {  // 这里可以改为while循环
            int h = height[i] < height[j] ? height[i++] : height[j--];
            max = std::max(max, (j-i+1)*h);  //+1是因为上一步的i,j增减了一个1
        }
        return max;
    }
};
// @lc code=end

