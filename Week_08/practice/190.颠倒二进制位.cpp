/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        uint32_t MASK = 1;
        for (int i=0;i<32;i++){
            if (n & MASK) ans |= 1 << (31-i);
            MASK <<= 1;
        }
        return ans;
    }
};
// @lc code=end

