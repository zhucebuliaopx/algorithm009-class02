/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
// class Solution {  // 二分法
// public:
//     bool isPerfectSquare(int num) {
//         if (num < 2) return true;
//         long left = 2;
//         long right = num/2;
//         while (left <= right) {
//             long x = left +(right-left)/2;
//             long res = x*x;
//             if (res < num){
//                 left = x+1;
//             }else if (res > num){
//                 right = x-1;
//             }else{
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {  // 牛顿迭代法
public:
    bool isPerfectSquare(int num){
        if (num < 2 ) return true;
        long x = num/2;
        while (x*x > num)
        {
            x = (x+num/x)/2;
        }
        return x*x == num;
    }
};
/*
f(X) = x^2-num;  f(x)=0对应的x即为解
f'(X) = 2x = f(x2)/(x2-x1);
=> x = (x+num/x)/2 ，x为近似解
*/
// @lc code=end

