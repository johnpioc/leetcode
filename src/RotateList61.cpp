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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        stack<ListNode*> nodes;
        ListNode* curr = head;
        while (curr != nullptr) {
            n++;
            nodes.push(curr);
            curr = curr->next;
        }

        if (n == 0 || k == 0) return head;

        k %= n;

        while (k > 0) {
            curr = nodes.top();
            nodes.pop();

            curr->next = head;
            head = curr;
            k--;
        }

        curr = nodes.top();
        curr->next = nullptr;

        return head;
    }
};