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
    ListNode* oddEvenList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode *pre = head, *curr = head->next;
        while (curr && curr->next) {
            ListNode* temp = pre->next;
            pre->next = curr->next;
            curr->next = curr->next->next;
            pre->next->next = temp;
            curr = curr->next;
            pre = pre->next;
        }
        return head;
    }
};
