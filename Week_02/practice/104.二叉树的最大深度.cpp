/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {  // dfs 深度遍历算法
//         if (!root) return 0;
//         int left_height = maxDepth(root->left);
//         int right_height = maxDepth(root->right);
//         return max(left_height, right_height)+1;
//     }
// };
/*
时间复杂度O(n)
空间复杂度O(logn):最坏的情况是树是完全不平衡的，递归将调用树的高度k次
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {  // bfs 广度遍历算法
        int hight = 0;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0;i--){
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            hight++;
        }
        return hight;
    }
};
/*
时间复杂度O(n)
空间复杂度O(n)
*/

// @lc code=end

