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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;

        deque<TreeNode*> toSearch;
        toSearch.push_back(root);
        bool reverse = true;

        while (!toSearch.empty()) {
            int size = toSearch.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = reverse ? toSearch.back() : toSearch.front();
                if (reverse) toSearch.pop_back();
                else toSearch.pop_front();

                level.push_back(curr->val);

                if (reverse) {
                    if (curr->left) toSearch.push_front(curr->left);
                    if (curr->right) toSearch.push_front(curr->right);
                } else {
                    if (curr->right) toSearch.push_back(curr->right);
                    if (curr->left) toSearch.push_back(curr->left);
                }
            }

            res.push_back(level);
            reverse = !reverse;
        }

        return res;
    }
};