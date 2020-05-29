/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
class Solution {
public:
    string removeOuterParentheses(string S) {
        int l_parent = 1;
        int r_parent = 0;
        string s;
        for (int i = 1; i < S.length(); i++) {
            if (S[i] == '(') {
                l_parent++;
            }else
            {
                r_parent++;
            }
            if (l_parent != r_parent){
                s.push_back(S[i]);
            }else{
                l_parent = 1;
                r_parent = 0;
                i++;
            }
            
        }
        return s;
    }
};
// @lc code=end

