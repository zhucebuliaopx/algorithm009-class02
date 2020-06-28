/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class TrieNode {
public:
    string word = "";
    vector<TrieNode*> nodes;
    TrieNode(): nodes(26, 0){}
};

class Solution {
public:
    vector<string> result;
    int rows, cols;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows ? board[0].size(): 0;
        if (rows == 0 || cols == 0) return result;
        
        // 构造Trie树
        TrieNode* root = new TrieNode();
        for (string word : words){
            TrieNode* cur = root;
            for (int i = 0; i < word.size(); i++){
                int idx = word[i] - 'a';
                if (cur->nodes[idx] == 0) cur->nodes[idx] = new TrieNode();
                cur = cur->nodes[idx];
            }
            cur->word = word;
        }

        for (int i = 0; i < rows;i++) {
            for (int j = 0; j < cols;j++){
                dfs(board, root, i, j);
            }
        }
        return result;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y){
        char c = board[x][y];
        if (c == '$' || root->nodes[c-'a'] == 0) return;
        root = root->nodes[c-'a'];
        if (root->word != ""){
            result.push_back(root->word);
            root->word = "";
        }
        board[x][y] = '$';
        if (x > 0) dfs(board, root, x-1, y);
        if (y > 0) dfs(board, root, x, y-1);
        if (x+1 < rows) dfs(board, root, x+1, y);
        if (y+1 < cols) dfs(board, root, x, y+1);
        board[x][y] = c;
    }
};
// @lc code=end

