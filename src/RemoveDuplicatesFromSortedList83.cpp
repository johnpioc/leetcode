/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int prevVal = -101;
        ListNode* curr = head;
        ListNode* prev;

        while (curr != nullptr) {
            if (curr->val == prevVal) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }

            prevVal = curr->val;
            curr = curr->next;
        }

        return head;
    }
};