/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val > l2->val){  //相当于维护了一个栈，每次放入两个值，返回其中较小的值，将l1,l2接下来的较大的两个继续入栈比较，先入栈的最小值最后弹出
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }else{
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
};
// @lc code=end

