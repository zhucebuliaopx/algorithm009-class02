/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> result;
//         map<string,int> memo;
//         int sub_index = 0;
//         string tmp;
//         for (string s : strs) {
//             tmp = s;
//             sort(tmp.begin(), tmp.end());
//             if (memo.count(tmp)){
//                 result[memo[tmp]].push_back(s);
//             }else{
//                 vector<string> v(1, s);
//                 result.push_back(v);
//                 memo[tmp] = sub_index++;
//             }
//         }
//         return result;
//     }
// };



class Solution {  // 核心思想，一个正整数可以由固定的几个质数相乘得到
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //26个字母的质数对应表
        int char_hash[26] = {
            2,  3,  5,  7,  11, 
            13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 
            53, 59, 61, 67, 71,
            73, 79, 83, 89, 97, 
            101 
        } ;
        vector<vector<string>> res;
        unordered_map<unsigned long, int> word_table;
        int index = 0; //对应res的二维下标

        for (auto str : strs){
            unsigned long hash_key = 1;
            for (auto ch : str){
                hash_key *= char_hash[ch-'a'];
            }
            if ( word_table.count(hash_key) > 0 ) {
                res[word_table[hash_key]].push_back(str);
            } else{
                vector<string> temp(1, str);
                res.push_back(temp);
                word_table[hash_key] = index++;
            }
        }
        return res;
        
    }
};


// @lc code=end

