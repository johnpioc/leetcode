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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }

    void inOrder(TreeNode* current, vector<int>& res) {
        if (current == nullptr) return;

        inOrder(current->left, res);
        res.push_back(current->val);
        inOrder(current->right, res);
    }
};