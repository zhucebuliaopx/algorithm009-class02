/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// class Solution {
// public:
//     map<vector<int>, int> mymap;

//     int climbStairs(int n) {
//         return climb_stairs(0, n);
//     }

//     int climb_stairs(int i, int n) {
//         vector<int> myv;
//         myv.push_back(i);
//         myv.push_back(n);
//         if (mymap[myv]) return mymap[myv];
//         if (i > n) return 0;
//         if (i == n) return 1;
//         int num = climb_stairs(i+1, n)+ climb_stairs(i+2, n);
//         if (!mymap[myv]) mymap[myv] = num;
//         return num;
//     }
// };

// class Solution {  // 转换为计算fib数列
// public:
//     int climbStairs(int n) {
//         if (n == 0) return 0;
//         int a1 = 0;
//         int a2 = 1;

//         for (int i=0; i<n;i++){
//             int t = a1;
//             a1 = a2;
//             a2 = t+a2;
//         }
//         return a2;
//     }
// };


//公式求解 原公式的n在程序里需要加1，程序里n是从0开始的
// class Solution {
// public:
//     int climbStairs(int n) {
//         return (pow((1+sqrt(5))/2, n+1)-pow((1-sqrt(5))/2, n+1))/sqrt(5);
//     }
// };

// class Solution {
// public:
//     int climbStairs(int n) {
//         return n <= 2 ? n : climbStairs(n-1)+climbStairs(n-2);
//     }
// };

// class Solution{
// public:
//     unordered_map<int, int> memo;
//     int climbStairs(int n){
//         if (n <= 2) return n;

//         if (memo.count(n) == 0){
//             memo[n] = climbStairs(n - 1)+climbStairs(n - 2);
//         }
//         return memo[n];
//     }
// };


class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n;i++){
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
}
/*
O(logn)
*/
// @lc code=end

