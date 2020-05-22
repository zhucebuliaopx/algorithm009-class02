/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
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
//     ListNode* swapPairs(ListNode* head) {
//         if (!head || !head->next) return head;

//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;
//         ListNode* prev = dummy;
//         while (head && head->next) {
//             ListNode* first = head;
//             ListNode* second = head->next;

//             prev->next = second;
//             first->next = second->next;
//             second->next = first;

//             prev = first;
//             head = prev->next;
//         }
//         return dummy->next;
//     }
// };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* h_next = head->next;

        h_next->next = swapPairs(h_next->next);

        head->next = h_next->next;
        h_next->next = head;

        return h_next;
    }
};
// @lc code=end

