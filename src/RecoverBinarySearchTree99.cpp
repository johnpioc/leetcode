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
    void recoverTree(TreeNode* root) {
        while (!build(root, new TreeNode(INT_MAX), new TreeNode(INT_MIN)));
    }

    bool build(TreeNode* current, TreeNode* maxNode, TreeNode* minNode) {
        if (current == nullptr) return true;

        if (current->val > maxNode->val) {
            swap(current->val, maxNode->val);
            return false;
        } else if (current->val < minNode->val) {
            swap(current->val, minNode->val);
            return false;
        } else {
            return 
                build(current->right, maxNode, current->val > minNode->val ? current : minNode) &&
                build(current->left, current->val < maxNode->val ? current : maxNode,minNode);
        }
    }
};