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
        if (head == nullptr) return head;

        ListNode* newHead = nullptr;
        ListNode* curr = nullptr;

        ListNode* l = head;
        ListNode* r = head->next;
        int currentCount = 0;

        while (r != nullptr) {
            if (l->val == r->val) {
                currentCount++;
            } else {
                if (currentCount == 0) {
                    if (curr == nullptr) {
                        curr = l;
                        newHead = curr;
                    } else {
                        curr->next = l;
                        curr = curr->next;
                    }

                    curr->next = nullptr;
                }

                l = r;
                currentCount = 0;
            }

            r = r->next;
        }

        if (currentCount == 0) {
            if (curr == nullptr) {
                curr = l;
                newHead = curr;
            } else {
                curr->next = l;
                curr = curr->next;
            }

            curr->next = nullptr;
        }

        return newHead;
    }
};