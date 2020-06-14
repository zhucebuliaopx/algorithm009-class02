/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
// class Solution {
// public:
//     int n;
//     int m;
//     int numIslands(vector<vector<char>>& grid) {
//         int count = 0;
//         n = grid.size();
//         if (n == 0) return count;
//         m = grid[0].size();
//         for (int i =0;i<n;i++) {
//             for (int j =0;j<m;j++) {
//                 if (grid[i][j] == '1'){
//                     dfs(grid,i, j);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

//     void dfs(vector<vector<char>>& grid, int i, int j) {
//         if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return;
//         grid[i][j] = 0;
//         dfs(grid, i+1, j);
//         dfs(grid, i-1, j);
//         dfs(grid, i, j+1);
//         dfs(grid, i, j-1);
//     }
// };


class Solution { // bfs
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int count = 0;
        for (int i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                if (grid[i][j] == '1'){
                    ++count;
                    grid[i][j] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({i, j});

                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first;
                        int col = rc.second;
                        if (row-1 >=0 && grid[row-1][col] == '1'){
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row+1 < nr && grid[row+1][col] == '1'){
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col-1 >=0 && grid[row][col-1] == '1'){
                            neighbors.push({row,col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col+1 < nc && grid[row][col+1] == '1'){
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }
        return count;
    }

};
// @lc code=end

