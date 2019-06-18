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
    ListNode* plusOne(ListNode* head) {
        return recursion_plus_one(head);
    }

    /*! \brief reverse list then add
     *
     *  reverse and keep updating the carrying bit
     *
     * \param head input head
     * \return modified list head
     */
    ListNode* reverse_then_add(ListNode* head)
    {
        if (!head) return head;
        ListNode* rev_head = reverse(head), *curr = rev_head, *pre = curr;
        int carry = 1;
        while (curr) {
            pre = curr;
            int t = curr -> val + carry;
            curr -> val = t % 10;
            carry = t / 10;
            if (carry == 0) break;
            curr = curr -> next;
        }
        if (carry) pre -> next = new ListNode(1);
        return reverse(rev_head);
    }

    /*! \brief Reverse the list
     *
     *  pointing to the head and reverse the list
     *
     * \param head initial head
     * \return end of the list with reversed order
     */
    ListNode* reverse(ListNode* head)
    {
        if (!head) return head;
        ListNode* dummy = new ListNode(-1), *curr = head;
        dummy -> next = head;
        while (curr && curr -> next) {
            ListNode* t = curr -> next;
            curr -> next = t -> next;
            t -> next = dummy -> next;
            dummy -> next = t;
        }
        return dummy -> next;
    }

    /*! \brief Recurion way
     *
     *  keep recurse until to the end of list
     *
     * \param head input list
     * \return modified list
     */
    ListNode* recursion_plus_one(ListNode* head)
    {
        if (!head) return head;
        int carry = recurse(head);
        // if need a new digit
        if (carry == 1) {
            ListNode* res = new ListNode(1);
            res -> next = head;
            return res;
        }
        return head;
    }
    /*! \brief Recurse method
     *
     *  keep recursion and do the plue one op in this function
     *
     * \param node starting point
     * \return if there is a carry then return 1 else 0
     */
    int recurse(ListNode* node)
    {
       if (!node) return 1;
       int carry = recurse(node -> next);
       int sum = node -> val + carry;
       node -> val = sum % 10;
       return sum / 10; // only happen when 9 + 1
    }
};
