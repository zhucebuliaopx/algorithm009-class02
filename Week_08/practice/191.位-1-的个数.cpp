/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t c = 0;
        while (n > 0) {
            n = n & (n-1);
            c++;
        }   
        return c;
    }
};
// @lc code=end

