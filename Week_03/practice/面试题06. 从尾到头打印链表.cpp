/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// class Solution {
// public:
//     vector<int> result;
//     vector<int> reversePrint(ListNode* head) {
//         if (!head) return result;
//         result = reversePrint(head->next);
//         result.emplace_back(head->val);
//         return result;
//     }
// };

/*
性能最差,每次返回的result造成大量内存浪费
*/

// class Solution {
// public:
//     vector<int> result;
//     vector<int> reversePrint(ListNode* head) {
//         stack<int> s;
//         while (head){
//             s.emplace(head->val);
//             head = head->next;
//         }
//         int length = s.size(); 
//         for (int i=0;i<length;i++){
//             result.emplace_back(s.top());
//             s.pop();
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> result;
    vector<int> reversePrint(ListNode* head) {
        if (!head) return result;
        reverse(head);
        return result;
    }

    void reverse(ListNode* head){
        if (!head) return;
        reverse(head->next);
        result.emplace_back(head->val);
    };
};

/*
性能最好
*/