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
    void remove(ListNode* current, int n, int* size, int index) {
        if (current == nullptr) {
            return;
        }

        (*size)++;
        remove(current->next, n, size, index + 1);

        // If prev
        if ((*size) - n == index) {
            ListNode* next = current->next;
            if (next != nullptr) {
                current->next = next->next;
            }
        }
    }


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        remove(head, n, &size, 1);

        if (size - n == 0) {
            return head->next;
        } else {
            return head;
        }
    }
};