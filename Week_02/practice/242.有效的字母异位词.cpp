/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.length() != t.length()) return false;
//         map<char, int> m;

//         for (int i = 0; i < s.length(); i++) {
//             m[s[i]]++;
//         }

//         for (int i = 0; i < t.length(); i++) 
//         {
//             if (m[t[i]] <= 0) return false;
//             m[t[i]]--;
//         }
//         return true;
//     }
// };


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s.compare(t) == 0;
    }
};
// @lc code=end

