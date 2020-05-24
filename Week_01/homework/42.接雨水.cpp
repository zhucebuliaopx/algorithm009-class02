/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;

        while (left < right) {
            if (height[left] < height[right]){
                left_max <= height[left] ? (left_max = height[left]): ans+= (left_max-height[left]);
                left++;
            }else{
                right_max <= height[right] ? (right_max = height[right]): ans+=(right_max-height[right]);
                right--;
            }
        }
        return ans;
    }
};
/*
思路解析：先将问题简化为计算每一个空缺的面积，宽为1，面积相当于左右两边的最小高度值与自身高度差，使用双指针可以保证左右同时遍历，整体遍历一遍即可，两边的最大高度动态更新
时间复杂度O(n): 只循环一遍
空间复杂度O(1): 使用了常数级别数量的变量
*/
// @lc code=end

