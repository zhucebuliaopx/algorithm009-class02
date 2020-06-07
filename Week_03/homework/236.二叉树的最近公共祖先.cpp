/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root || root == p || root == q) return root;
//         TreeNode* left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* right = lowestCommonAncestor(root->right, p, q);
//         if (!left) return right;
//         if (!right) return left;
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p, q);
        return res;        
    }

    bool traverse(TreeNode* cur, TreeNode*p, TreeNode*q) {
        if (cur == NULL ) return false;

        int left = traverse(cur->left, p, q);
        int right = traverse(cur->right, p, q);

        int mid = (cur == p || cur == q) ? 1 : 0;
        if (mid + left + right  >= 2){  // 这里相当于把第一种做法的最后2个返回 和开头的pq判断合并到了一起，只要2个满足条件，将该值返回或者说赋给res节点
            this->res = cur;
        }
        return (mid + left + right > 0);
    }
};

/*
效率更高
*/
// @lc code=end

