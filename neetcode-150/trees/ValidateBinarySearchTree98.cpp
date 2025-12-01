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
    bool isValidBST(TreeNode* root) {
        vector<int> path;
        inOrder(root, &path);

        for (int i = 1; i < path.size(); i++) {
            if (path[i] <= path[i - 1])
                return false;
        }

        return true;
    }

    void inOrder(TreeNode* current, vector<int>* path) {
        if (current == nullptr)
            return;

        inOrder(current->left, path);
        (*path).push_back(current->val);
        if ((*path).size() > 1 && current->val <= (*path)[(*path).size() - 2]) {
            return;
        }

        inOrder(current->right, path);
    }
};