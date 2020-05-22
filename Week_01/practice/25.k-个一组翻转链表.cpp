/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* target = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return target;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* end = dummy;

        while(end->next){
            for (int i = 0;i<k && end;i++) end = end->next;
            if (!end) break;
            ListNode* cur = pre->next;
            ListNode* next = end->next;  // 记录下一条要反转的链表
            end->next = nullptr;  // 临时将链表断开
            pre->next = reverse(cur);  // 局部问题简化为链表反转
            cur->next = next;  // cur指针变为前一条临时链表的尾指针，与剩下的链表重新链接
            pre = cur;  // 初始化pre指针
            end = pre;                                                               
        }

        return dummy->next;
    }
};
/*
时间复杂度O(2kn):
空间复杂度O(1): 使用了常数个指针变量
*/
// @lc code=end

