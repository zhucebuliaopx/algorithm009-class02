/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size();
        int m = board[0].size();
        dfs(board, click[0], click[1], n, m);
        return board;
    }

    void dfs(vector<vector<char>> &board, int x, int y, int n, int m) {
        if (x < 0 || y < 0 || x >= n || y >=m) return;

        if (board[x][y] == 'E'){
            board[x][y] = 'B';
            int count = judge(board, x, y, n, m);
            if (count == 0) {
                for (int i = 0; i < 8; i++) {
                    dfs(board, x+dx[i], y+dy[i], n, m);
                }
            }else{
                board[x][y] = (char)(count+'0');
            }

        }else if (board[x][y] == 'M'){
            board[x][y] = 'X';
        }
    }

    int judge(vector<vector<char>> &board, int x, int y, int n, int m){
        int count = 0;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (board[nx][ny] == 'M') count++;
        }
        return count;
    }
};
// @lc code=end

