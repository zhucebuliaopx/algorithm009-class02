/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         return dp(text1, text2, text1.size() - 1, text2.size() -1 );
//     }

//     int dp(string text1, string text2, int m, int n) {
//         if ( m == -1 || n == -1 ) return 0;
//         if (text1[m] == text2[n] ) {
//             return dp(text1, text2, m - 1, n - 1) + 1;   
//         }else{
//             return max(dp(text1, text2, m - 1, n), dp(text1, text2, m, n -  1));
//         }
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2){
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1);

        for (int i=0; i< m+1; i++){
            dp[i].resize(n+1);
        }

        for (int i=1; i< m+1; i++){
            for (int j=1; j< n+1; j++){
                if (text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i-1][j-1] + 1; 
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

