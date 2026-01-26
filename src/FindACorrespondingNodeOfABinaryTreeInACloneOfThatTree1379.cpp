/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return inOrderTraversal(original, cloned, target);
    }

    TreeNode* inOrderTraversal(TreeNode* currentA, TreeNode* currentB, TreeNode* target) {
        if (currentA == nullptr) return nullptr;

        TreeNode* left = inOrderTraversal(currentA->left, currentB->left, target);
        TreeNode* current = currentA->val == target->val ? currentB : nullptr;
        TreeNode* right = inOrderTraversal(currentA->right, currentB->right, target);

        return left == nullptr ? (current == nullptr ? right : current) : left;
    }
};