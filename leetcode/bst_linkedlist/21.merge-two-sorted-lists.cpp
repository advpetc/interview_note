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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *dummy = new ListNode(-1), *curr = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                dummy->next = l1;
                l1 = l1->next;
            } else {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        if (l1)
            dummy->next = l1;
        else if (l2)
            dummy->next = l2;
        return curr->next;
    }
};