/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return buildTreeHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int p_start, int p_end, vector<int>& inorder, int i_start, int i_end){
        if (p_start == p_end) return NULL;

        int root_val = preorder[p_start];
        int i_root_index = 0;
        TreeNode* root = new TreeNode(root_val);
        for (int i=i_start;i<i_end;i++){
            if (inorder[i] == root_val) {
                i_root_index = i;
                break;
            }
        }
        int left_num = i_root_index - i_start;

        root->left = buildTreeHelper(preorder, p_start+1, p_start+left_num+1, inorder, i_start, i_root_index);
        root->right = buildTreeHelper(preorder, p_start+left_num+1, p_end, inorder, i_root_index+1, i_end);
        return root;
    }

};
// @lc code=end

