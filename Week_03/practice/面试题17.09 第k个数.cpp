/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         priority_queue<double,vector<double>, greater<double>> q;
//         double res = 1;

//         for (int i = 1; i < n; ++i) {
//             q.push(res*2);
//             q.push(res*3);
//             q.push(res*5);
//             res = q.top();
//             q.pop();
//             while (!q.empty() && res == q.top()) {
//                 q.pop();
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int nthUglyNumber(int n) {
        int p2, p3, p5;
        p2 = p3 = p5 = 0;
        vector<int> dp(n);
        dp.at(0) = 1;

        for (int i = 1; i <n; i++) {
            dp.at(i) = min(min(2*dp.at(p2), 3*dp.at(p3)), 5*dp.at(p5));
            if (dp.at(i) == 2*dp.at(p2)) p2++;
            if (dp.at(i) == 3*dp.at(p3)) p3++;
            if (dp.at(i) == 5*dp.at(p5)) p5++;
        }
        return dp.at(n-1);
    }
};
// @lc code=end

