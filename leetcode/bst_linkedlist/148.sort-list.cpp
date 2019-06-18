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
        ListNode* sortList(ListNode* head) {
            return mergeSort(head);
        }

        /*! \brief Merge sort
         *
         *  using merge sort to reach n log n
         *
         * \param head inputs
         * \return sorted head
         */
        ListNode* mergeSort(ListNode* head)
        {
            if (!head || !head -> next) return head;
            ListNode* slow = head, *fast = head, *pre = head;
            while (fast && fast -> next) {
                pre = slow;
                slow = slow -> next;
                fast = fast -> next -> next;
            }
            pre -> next = NULL; // break the list: now only two part (head to pre and slow to end)
            return merge(mergeSort(head), mergeSort(slow));
        }

        /*! \brief merge step
         *
         *  always put the smaller node to the next to dummy, then increment curr
         *
         * \param l1 from head to mid point, which is already broken to second part
         * \param l2 from mid + 1 point to end point, which is already broken to first part
         * \return the sorted partial list
         */
        ListNode* merge(ListNode* l1, ListNode* l2)
        {
            ListNode* dummy = new ListNode(-1);
            ListNode* curr = dummy;
            while (l1 && l2) {
                if (l1 -> val < l2 -> val) {
                    curr -> next = l1;
                    l1 = l1 -> next;
                } else {
                    curr -> next = l2;
                    l2 = l2 -> next;
                }
                curr = curr -> next;
            }
            if (l1) curr -> next = l1;
            if (l2) curr -> next = l2;
            return dummy -> next;
        }
};
