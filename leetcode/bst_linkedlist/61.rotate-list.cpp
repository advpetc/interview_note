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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head)
            return NULL;
        int n = 1;
        ListNode* curr = head;
        while (curr->next) {
            ++n;
            curr = curr->next;
        }

        curr->next = head;
        int m = n - k % n;
        for (int i = 0; i < m; ++i) {
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = NULL;
        return newHead;
    }
};
