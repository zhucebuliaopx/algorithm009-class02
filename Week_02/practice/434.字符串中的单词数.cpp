/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 && s[0] != ' ') {
                count++;
            }else if (i > 0 && s[i-1] == ' ' && s[i] != ' '){
                count++;
            }
        }
        return count;
    }
};


// class Solution {
// public:
//     int countSegments(string s) {
//         string word;
//         istringstream lines(s);  //前一句是从string中读取数据，后一句是使用输入运算符来读取lines中每个元素
//         int count = 0;
//         while(lines >> word)
//         {
//             ++count;
//         }
//         return count;
//     }
// };
// @lc code=end

