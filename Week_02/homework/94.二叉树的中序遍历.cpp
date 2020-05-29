/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
class Solution {  //中序遍历->左根右
public:
    void helper(TreeNode * root, vector<int> &result) {
        if (root != NULL) {
            if (root->left != NULL){  //left
                helper(root->left, result);
            }
            result.push_back(root->val); // 根
            if (root->right != NULL){
                helper(root->right, result);  // right
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
};
// @lc code=end

