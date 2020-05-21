/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        
        ListNode* fp = head->next;
        ListNode* sp = head;

        while (fp != sp) 
        {
            if (!fp || !fp->next) return false;

            sp = sp->next;
            fp = fp->next->next;
        }
        return true;
    }
};
// @lc code=end

