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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        return getMin(root, 1);
    }

    int getMin(TreeNode* node, int current) {
        if (node == nullptr) return INT_MAX;
        if (node->left == nullptr && node->right == nullptr) return current;

        current++;

        return min(getMin(node->left, current), getMin(node->right, current));
    }
};