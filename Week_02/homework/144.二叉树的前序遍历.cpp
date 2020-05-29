/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
class Solution {
public:
    void helper(TreeNode *root, vector<int> &v) {
        if (root){
            v.push_back(root->val);
            if (root->left) {
                helper(root->left, v);
            }
            if (root->right) {
                helper(root->right, v);
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        return v;
    }
};
// @lc code=end

