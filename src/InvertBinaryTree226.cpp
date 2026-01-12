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

    void swapChildren(TreeNode* node) {
        if (node == nullptr) return;

        // If both children exist
        if (node->left != nullptr && node->right != nullptr) {
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
            swapChildren(node->left);
            swapChildren(node->right);
        }
        // If only left child exists
        else if (node->left != nullptr && node->right == nullptr) {
            node->right = node->left;
            node->left = nullptr;
            swapChildren(node->right);
        }
        // If only right child exists
        else if (node->right != nullptr && node->left == nullptr) {
            node->left = node->right;
            node->right = nullptr;
            swapChildren(node->left);
        }
        // If no children, do nothign
    }

    TreeNode* invertTree(TreeNode* root) {
        swapChildren(root);
        return root;
    }
};