/**
* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> seen;

        bool hasCycle = false;

        while (head != nullptr) {
            // Check if we've already seen it. If we have, break the cycle and return true
            if (seen.contains(head)) {
                hasCycle = true;
                break;
            }

            // If we haven't seen it, append it to set
            seen.insert(head);

            // Move onto next node
            head = head->next;
        }

        return hasCycle;
    }
};