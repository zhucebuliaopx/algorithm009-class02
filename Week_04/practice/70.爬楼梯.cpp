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
class Solution {
public:
    int climbStairs(int n) {
        return (pow((1+sqrt(5))/2, n+1)-pow((1-sqrt(5))/2, n+1))/sqrt(5);
    }
};
/*
O(logn)
*/
// @lc code=end

