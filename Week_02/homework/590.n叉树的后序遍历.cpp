/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
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
//     vector<int> postorder(Node* root) {
//         if (!root) return result;

//         for (auto c_root: root->children){
//             postorder(c_root);
//         }
//         result.push_back(root->val);        
//         return result;
//     }
// };

class Solution {
public:
    vector<int> result;
    vector<int> postorder(Node* root) {
        if (!root) return result;      
        stack<Node*> st;

        st.push(root);
        while (!st.empty()) 
        {
            Node* tmp = st.top();
            st.pop();
            result.push_back(tmp->val);
            for (auto c : tmp->children){
                st.push(c);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

