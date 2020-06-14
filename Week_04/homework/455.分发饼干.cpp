/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0, si = 0;
        while (gi < g.size() && si < s.size()) {
            if (g[gi] <= s[si]) gi++;
            si++;
        }
        return gi;
    }
};
// @lc code=end

