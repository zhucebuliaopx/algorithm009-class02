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


// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         if (m == 0) return false;
//         int n = matrix[0].size();
//         if (n == 0) return false;

//         for (int i = 0; i < m; i++) {
//             if (matrix[i][n-1] < target) continue;
//             int j = n/2;
//             if (matrix[i][j] <= target) {
//                 for (;j<n;j++){
//                     if (matrix[i][j] == target) return true;
//                     if (matrix[i][j] > target) return false;
//                 }
//             };
//             if (matrix[i][j] >= target){
//                 for (;j>=0;j--){
//                     if (matrix[i][j] == target) return true;
//                     if (matrix[i][j] < target) return false;
//                 }
//             };
//             break;
//         }
//         return false;
//     }
// };


// class Solution{
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target){
//         int m = matrix.size();
//         if (m == 0) return false;
//         int n = matrix[0].size();
//         if (n == 0) return false;

//         for (int i = 0; i <m;i++){
//             if (matrix[i][0] > target) return false;
//             if (matrix[i][n-1] < target) continue;
//             for (int j = 0; j <n;j++){
//                 if ( target == matrix[i][j]) return true;
//             }
//         }
//         return false;
//     }
// };


class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int l = 0;
        int r = m*n-1;
        while (l <= r){
            int mid_index = l + (r -  l)/2;
            int mid = matrix[mid_index/n][mid_index%n];
            if (mid < target) {
                l = mid_index+1;
            }else if (mid > target) {
                r = mid_index - 1;
            }else{
                return true;
            }
        } 

        return false;
    }
};
// @lc code=end

