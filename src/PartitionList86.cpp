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
    ListNode* partition(ListNode* head, int x) {
        vector<int> firstPartition;
        vector<int> secondPartition;
        ListNode* curr = head;

        // Get less than first
        while (curr != nullptr) {
            if (curr->val < x) firstPartition.push_back(curr->val);
            else secondPartition.push_back(curr->val);

            curr = curr->next;
        }

        // Change values
        curr = head;
        for (int num : firstPartition) {
            curr->val = num;
            curr = curr->next;
        }

        for (int num : secondPartition) {
            curr->val = num;
            curr = curr->next;
        }

        return head;
    }
};