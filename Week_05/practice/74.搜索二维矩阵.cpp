/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         if (m == 0) return false;

//         int n = matrix[0].size();
//         if (n == 0) return false;

//         for (int i = 0; i < m; i++) {
//             if (matrix[i][n-1] < target) continue;
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == target) return true;
//             }
//             break;
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][n-1] < target) continue;
            int j = n/2;
            if (matrix[i][j] <= target) {
                for (;j<n;j++){
                    if (matrix[i][j] == target) return true;
                    if (matrix[i][j] > target) return false;
                }
            };
            if (matrix[i][j] >= target){
                for (;j>=0;j--){
                    if (matrix[i][j] == target) return true;
                    if (matrix[i][j] < target) return false;
                }
            };
            break;
        }
        return false;
    }
};
// @lc code=end

