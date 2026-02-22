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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--;
        right--;

        vector<int> toReverse;
        int index = 0;

        ListNode* curr = head;
        while (index <= right) {
            if (left <= index) toReverse.push_back(curr->val);
            curr = curr->next;
            index++;
        }

        curr = head;
        for (int i = 0; i <= right; i++) {
            if (left <= i) {
                curr->val = toReverse[toReverse.size() - (i - left) - 1];
            }

            curr = curr->next;
        }

        return head;
    }
};