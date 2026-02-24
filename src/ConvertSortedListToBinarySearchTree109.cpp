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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;

        vector<TreeNode*> nodes;
        ListNode* curr = head;
        while (curr != nullptr) { nodes.push_back(new TreeNode(curr->val)); curr = curr->next; }
        build(0, nodes.size() - 1, nodes);
        return nodes[(nodes.size() - 1) / 2];
    }

    void build(int l, int r, vector<TreeNode*>& nodes) {
        if (l > r - 1) return;
        int m = (l + r) / 2;
        TreeNode* mid = nodes[m];

        int left = (l + m - 1) / 2;
        if (left >= l && left < m) {
            mid->left = nodes[left];
            build(l, m - 1, nodes);
        }

        int right = (m + r + 1) / 2;
        if (m < right && right <= r) {
            mid->right = nodes[right];
            build(m + 1, r, nodes); 
        }
          
    }
};