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
    void reorderList(ListNode* head)
    {
        if (!head || !head->next)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL; // break the list
        ListNode *last = mid, *pre = NULL;
        while (last) {
            ListNode* next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        while (head && pre) {
            ListNode* next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
    }
};
