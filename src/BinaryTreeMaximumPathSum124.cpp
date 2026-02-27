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
    int maxPathSum(TreeNode* root) {
        int sum = -1001;
        return max(sum, explore(root, sum));
    }

    int explore(TreeNode* current, int& sum) {
        if (!current) return -1001;

        int l = explore(current->left, sum);
        int r = explore(current->right, sum);
        int c = current->val;
        sum = max({l, r, l + c + r, sum});

        return max({current->val + l, current->val + r, current->val});
    }
};