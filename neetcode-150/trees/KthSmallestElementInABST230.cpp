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
    void inOrder(TreeNode* node, int* k, int* output) {
        if (node == nullptr) return;

        inOrder(node->left, k, output);

        (*k)--;
        if (*k == 0) {
            (*output) = node->val;
            return;
        }

        inOrder(node->right, k, output);
    }

    int kthSmallest(TreeNode* root, int k) {
        int output;
        inOrder(root, &k, &output);
        return output;
    }
};