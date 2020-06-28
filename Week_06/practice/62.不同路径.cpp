/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//        cout << m << endl;
//        cout << n << endl;
//        vector<int> cur(n);
//        for (int i = 0; i < n; ++i){
//            cur[i] = 1;
//        }
//        for (int i = 1; i <m;i++){
//            for (int j = 1; j <n; ++j){
//                cur[j] += cur[j-1];
//            }
//        }
//        return cur[n-1];
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n){
        vector<int> cur(m);
        for (int i = 0; i <m;i++){
            cur[i] = 1;
        }

        for (int i=1;i<n;i++){
            for (int j =1;j<m;j++){
                cur[j] += cur[j-1];
            }
        }
        return cur[m-1];
    }
};
// @lc code=end

