/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {   // 直接看第一的解答，数学思维很重要，赶快捡起来
        return (num - 1)% 9 +1;
    }
};
// @lc code=end

