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

/*
二者差异：
    小顶堆（优先队列）是先存在排，会导致有许多重复数据，多余的空间占用，可以用集合等去重，
    动态规划的方式是先排在存，使用三个指针分别处理235倍数的情况，先比较对应值大小，在存储较小值，空间占用更优
*/
// @lc code=end

