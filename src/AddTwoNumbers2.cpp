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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(0);
        add(l1, l2, newHead, 0);
        return newHead;
    }

    void add(ListNode* a, ListNode* b, ListNode* current, int carry) {
        if (a == nullptr && b == nullptr) {
            if (carry > 0) {
                current->next = new ListNode(carry);
            }
            return;
        }
        
        int aVal = a != nullptr ? a->val : 0;
        int bVal = b != nullptr ? b->val : 0;
        int sum = aVal + bVal + carry;
        current->val = sum % 10;

        ListNode* aNext = a != nullptr ? a->next : nullptr;
        ListNode* bNext = b != nullptr ? b->next : nullptr;

        if (aNext != nullptr || bNext != nullptr) {
            current->next = new ListNode(0);
            current = current->next;
        }

        add(aNext, bNext, current, sum / 10);
    }
};