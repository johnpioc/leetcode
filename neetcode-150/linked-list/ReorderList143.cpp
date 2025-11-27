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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* current = head;
        while (current != nullptr) {
            nodes.push_back(current);
            current = current->next;
        }

        ListNode* currentNode = head;
        int left = 1;
        int right = nodes.size() - 1;
        while (left <= right) {
            currentNode->next = nodes[right--];
            currentNode = currentNode->next;

            if (left <= right) {
                currentNode->next = nodes[left++];
                currentNode = currentNode->next;
            }
        }

        currentNode->next = nullptr;
    }
};