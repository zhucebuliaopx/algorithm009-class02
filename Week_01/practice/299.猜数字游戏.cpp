/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int count[10] = {0};  // 数字0-9
        int bull = 0, cow = 0;
        
        for (int i = 0; secret[i]; i ++) {
            if (secret[i] == guess[i]) bull ++;
            else {
                cow += (count[secret[i] - '0'] ++ < 0);  //将字符转换为数组索引操作，此处满足<0的要求说明guess字符串中也存在，cow+1
                cow += (count[guess[i] - '0'] -- > 0);  //同上，此处满足>0的要求说明secret字符串中也存在，cow+1
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
/*
时间复杂度O(n): 只有一次循环遍历
空间复杂度O(1): 有一个O(10)的数组，简化为O(1)
*/
// @lc code=end

