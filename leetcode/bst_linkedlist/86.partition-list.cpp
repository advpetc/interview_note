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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *curr = head;
        while (pre->next && pre->next->val < x) {
            pre = pre->next;
        }
        curr = pre;
        while (curr->next) {
            if (curr->next->val < x) {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
                pre = pre->next;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
