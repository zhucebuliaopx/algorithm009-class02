/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);
        for (int i = 0; i < n;i++) {
            dp[i] = 0;
        }

        for (int i = m-1; i >= 0;i--) {
            for (int j = n-1; j >= 0;j--) {
                // if (i == m-1 && j < n-1) {
                //     dp[j] = dp[j+1] + grid[i][j];
                // }else if (){

                // }
                if (i == m-1 && j < n-1) {
                    dp[j] = grid[i][j]+dp[j+1];
                }else if (j == n-1 && i < m -1) {
                    dp[j] = grid[i][j]+dp[j];
                }else if (i < m-1 && j < n -1){
                    dp[j] = grid[i][j]+min(dp[j], dp[j+1]);
                }else
                {
                    dp[j] = grid[i][j];
                }
            }
        }
        return dp[0];
    }
};
// @lc code=end

