/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         vector<int> dp(m);
//         bool iflag = false;
//         bool jflag = false;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j){
//                 if (obstacleGrid[i][j] == 1){
//                     dp[j] = 0;
//                     if (i == 0) iflag = true;
//                     if (j == 0) jflag = true;
//                 }else if (i == 0){
//                     dp[j] = iflag ? 0 : 1; 
//                 }else if (j == 0){
//                     dp[j] = jflag ? 0 : 1; 
//                 }else{
//                     dp[j] += dp[j-1];
//                 }
//             }
//         }
//         return dp[m-1];
//     }
// };


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int *dp = new int[m];
        bool iflag = false;
        bool jflag = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j){
                if (obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                    if (i == 0) iflag = true;
                    if (j == 0) jflag = true;
                }else if (i == 0){
                    dp[j] = iflag ? 0 : 1; 
                }else if (j == 0){
                    dp[j] = jflag ? 0 : 1; 
                }else{
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[m-1];
    }
};

// @lc code=end

