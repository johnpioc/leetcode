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
    int sumNumbers(TreeNode* root) {
        vector<int> current = {};
        return dfs(root, current);
    }

    int dfs(TreeNode* node, vector<int>& curr) {
        curr.push_back(node->val);

        int total = 0;

        if (!node->left && !node->right) {
            for (int i = 0; i < curr.size(); i++) total += curr[i] * pow(10, curr.size() - i - 1);
            curr.pop_back();
            return total;
        }

        total += node->left ? dfs(node->left, curr) : 0;
        total += node->right ? dfs(node->right, curr) : 0;
        curr.pop_back();

        return total;
    }
};