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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        ListNode* sortedList = new ListNode();
        ListNode* current = sortedList;

        while (list1 != nullptr || list2 != nullptr) {
            // 1. Find the minimum value between both lists with respect to if the lists are exhausted
            if (list1 != nullptr && list2 == nullptr) {
                current->val = list1->val;
                list1 = list1->next;;
            } else if (list1 == nullptr && list2 != nullptr) {
                current->val = list2->val;
                list2 = list2->next;
            } else {
                int minimumValue = min(list1->val, list2->val);

                if (minimumValue == list1->val) {
                    list1 = list1->next;
                } else {
                    list2 = list2->next;
                }

                current->val = minimumValue;
            }

            // 2. Move onto the next node
            if (list1 != nullptr || list2 != nullptr) {
                ListNode* next = new ListNode();
                current->next = next;
                current = current->next;
            }
        }

        return sortedList;
    }
};