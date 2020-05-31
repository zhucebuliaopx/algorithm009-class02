/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// class Solution {
// public:
//     vector<int> result;
//     vector<int> preorder(Node* root) {
//         if (!root) return result;

//         stack<Node*> st;

//         st.push(root);
//         while (!st.empty()){
//             Node* tmp = st.top();
//             st.pop();
//             result.push_back(tmp->val);
//             for (int i=tmp->children.size()-1;i<tmp->children.size();i--){  // 这里是为了保证前序遍历，stack是先进后出的
//                 st.push(tmp->children[i]);
//             }
//         }
//         return result;
//     }
// };

/*
时间复杂度O(m):m为节点个数
空间复杂度O(m):相比较递归要更节省内存，栈的操作每次都会释放掉
*/

class Solution{
public:
    vector<int> result;
    vector<int> preorder(Node* root) {
        if (!root) return result;
        result.push_back(root->val);
        for (auto c: root->children)
        {
            preorder(c);
        }
        return result;
    }

};
/*
时间复杂度O(m)
空间复杂度O(logm)：相当于一次性将所有节点压入栈中，归的时候才释放
*/

// @lc code=end

