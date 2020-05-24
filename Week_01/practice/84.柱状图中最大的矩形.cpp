/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights){ 
        int ans = 0;
        vector<int> st;  // 辅助栈，帮助保存左边的最小值边界
        heights.insert(heights.begin(), 0);  // 前后各加一个0，保证源数组首尾索引的面积计算
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.back()] > heights[i])  // 满足要求是说明找到右边界，此时可以计算面积
            {
                int cur = st.back();
                st.pop_back();  // 将当前值索引弹出栈顶，方便计算left
                int left = st.back() + 1;  
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);  // 此处的1表示矩形宽度，与上文的+1，-1对应
            }
            st.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

