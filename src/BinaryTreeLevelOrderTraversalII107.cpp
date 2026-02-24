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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;

        deque<TreeNode*> toSearch;
        toSearch.push_back(root);

        build(toSearch, res);
        return res;
    }

    void build(deque<TreeNode*>& toSearch, vector<vector<int>>& res) {
        if (toSearch.empty()) return;

        vector<int> level;
        int size = toSearch.size();
        for (int i = 0; i < size; i++) {
            TreeNode* curr = toSearch.front();
            toSearch.pop_front();
            level.push_back(curr->val);

            if (curr->left != nullptr) toSearch.push_back(curr->left);
            if (curr->right != nullptr) toSearch.push_back(curr->right);
        }

        build(toSearch, res);
        res.push_back(level);
    }
};