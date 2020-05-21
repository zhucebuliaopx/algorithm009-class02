/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
//     ListNode* reverseList(ListNode* head) {
//         if ( !head || !head->next ) return head;
//         ListNode* target = reverseList(head->next);
//         head->next->next = head;  // 这里每次只能使用head自己完成交换，保证target始终指向最后的头节点
//         head->next = nullptr;
//         return target;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next ) return head;
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while ( cur ) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if ( !head || !head->next ) return head;
//         ListNode* prev = nullptr;
//         ListNode* next = head;

//         while ( head ) {
//             next = next->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }
//         return prev;
//     }
// };
// @lc code=end

