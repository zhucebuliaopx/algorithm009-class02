/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for (auto &w: wordList) s.insert(w);

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        string tmp;
        int step;

        while (!q.empty()) {
            if (q.front().first == endWord){
                return (q.front().second);
            }
            tmp = q.front().first;
            step = q.front().second;
            q.pop();

            char ch;
            for (int i = 0;i< tmp.length();i++){
                ch = tmp[i];
                for (char c='a';c <= 'z';c++){
                    if (ch == c) continue;
                    tmp[i] = c;
                    if (s.find(tmp) != s.end()){
                        q.push({tmp, step+1});
                        s.erase(tmp);
                    }
                }
                tmp[i] = ch;
            }
        }
        return 0;
    }
};
// @lc code=end

