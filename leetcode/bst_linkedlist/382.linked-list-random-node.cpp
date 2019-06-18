/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* head;

public:
    /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
      one node. */
    Solution(ListNode* head)
        : head(head)
    {
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int res = head->val, i = 2;
        ListNode* curr = head->next;
        while (curr) {
            int j = rand() % i;
            if (j == 0)
                res = curr->val;
            ++i;
            curr = curr->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
