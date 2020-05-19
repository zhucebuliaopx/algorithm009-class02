/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
   int climbStairs(int n) {
        int *memo = new int[n+1];
        return climb_stairs(0, n, memo);
    }

    int climb_stairs(int i, int n, int *m) {
        if (i > n) return 0;
        if (i == n) return 1;
        if (m[i] > 0){
            return m[i];
        }

        m[i] = climb_stairs(i+1, n, m)+ climb_stairs(i+2, n, m);

        int num = m[i];
        return num;
    }
};
// @lc code=end

