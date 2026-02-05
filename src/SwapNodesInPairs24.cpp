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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* current = head;
        ListNode* next = head->next;
        ListNode* prev = nullptr;
        ListNode* newHead = next ? next : head;

        while (current && next) {
            ListNode* temp = next->next;
            next->next = current;
            current->next = temp;
            if (prev) prev->next = next;

            prev = current;
            current = temp;
            if (current) next = current->next;
        }

        return newHead;
    }
};