/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int m = 0; m < s.size();m+=2*k){
            int i = m;
            int j = min(m+k-1, int(s.size()-1));
            while(i<j){
                char a = s[i];
                s[i++] = s[j];
                s[j--] = a;
            }
        }
        return s;
    }
};
// @lc code=end

