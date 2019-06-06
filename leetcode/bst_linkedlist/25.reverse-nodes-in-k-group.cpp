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
    ListNode* reverseKGroup(ListNode* head, int k) { return method1(head, k); }

    /******************************************************************************
     * Function:         ListNode* method1
     *                   two functions
     * Where:
     * Return:           head of the reversed linkedlist
     * Error:
     *****************************************************************************/
    ListNode* method1(ListNode* head, int k)
    {
        if (!head || k == 1)
            return head;
        ListNode *dummy = new ListNode(-1), *pre = dummy, *curr = head;
        dummy->next = head;
        for (int i = 1; curr; ++i) {
            if (i % k == 0) {
                pre = reverseOneGroup(pre, curr->next);
                curr = pre->next;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }

    /*! \brief reverse one group of listedlist
     *
     *  helper function for method1
     *
     * \param pre previous node (the starting point)
     * \param next last node (the ending point)
     * \return last node of the reversed linkedlist
     */
    ListNode* reverseOneGroup(ListNode* pre, ListNode* next)
    {
        ListNode *last = pre->next, *curr = last->next;
        while (curr != next) {
            last->next = curr->next;
            curr->next = pre->next;
            pre->next = curr;
            curr = last->next;
        }
        return last;
    }
};
