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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (ListNode* head : lists) {
            while (head != nullptr) {
                pq.push(head->val);
                head = head->next;
            }
        }

        ListNode* newHead = new ListNode();
        ListNode* curr = newHead;
        ListNode* prev = nullptr;

        while (!pq.empty()) {
            curr->val = pq.top();
            curr->next = new ListNode();
            prev = curr;
            curr = curr->next;

            pq.pop();
        }

        if (prev != nullptr) prev->next = nullptr;
        else return nullptr;

        return newHead;
    }
};