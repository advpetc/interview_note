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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        // offset
        for (int i = 0; i < m - 1; ++i) {
            pre = pre->next;
        }
        ListNode* curr = pre->next;
        for (int i = m; i < n; ++i) {
            ListNode* t = curr->next;
            curr->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy->next;
    }
};
