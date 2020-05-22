/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* fast = head;
//         ListNode* slow = head;

//         while (true) {
//             if (!fast || !fast->next) return NULL;

//             fast = fast->next->next;
//             slow = slow->next;           
//             if (fast == slow){
//                 fast = head;
//                 while (true){
//                     if (fast == slow) return fast;
//                     fast = fast->next;
//                     slow = slow->next;
//                 }
//             }
//         }
//         return NULL;
//     }
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (true) {
            if (!fast || !fast->next) return NULL;

            fast = fast->next->next;
            slow = slow->next;           
            if (fast == slow) break;
        }
        fast = head;
        while (true){
            if (fast == slow) return fast;
            fast = fast->next;
            slow = slow->next;
        }
        return NULL;
    }
};
/*
复杂度分析：
  时间复杂度O(n): 第一个循环慢指针步数小于n，第二个循环慢指针步数依然小于n
  空间复杂度O(1): 使用双指针，空间复杂度为常数大小
*/
// @lc code=end

