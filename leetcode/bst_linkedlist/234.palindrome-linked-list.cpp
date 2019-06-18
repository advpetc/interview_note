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
    bool isPalindrome(ListNode* head) { return reverse_method(head); }

    /*! \brief Using stack
     *
     *  using slow and fast pointers to track the mid and then use stack to
     * compare
     *
     * \param head Parameter description
     * \return Return parameter description
     */
    bool stack_method(ListNode* head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        stack<int> s;
        s.push(head->val);
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        if (!fast->next)
            s.pop();
        while (slow->next) {
            slow = slow->next;
            if (slow->val != s.top())
                return false;
            s.pop();
        }
        return true;
    }

    /*! \brief reverse list
     *
     *  when found the mid, reverse the rest, then use two pointers to check
     *
     * \param head input
     * \return is or not palindrome
     */
    bool reverse_method(ListNode* head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *last = slow->next, *pre = head;
        while (last->next) {
            ListNode* temp = last->next;
            last->next = temp->next;
            temp->next = slow->next;
            slow->next = temp;
        }
        while (slow->next) {
            slow = slow->next;
            if (pre->val != slow->val)
                return false;
            pre = pre->next;
        }
        return true;
    }
};
