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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> array;
        build(root, 0, array, targetSum, res);
        return res;
    }

    void build(TreeNode* current, int currentSum, vector<int>& array, int targetSum, vector<vector<int>>& res) {
        if (current == nullptr) return;

        array.push_back(current->val);
        currentSum += current->val;

        if (currentSum == targetSum && current->left == nullptr && current->right == nullptr) res.push_back(array);
        else {
            build(current->left, currentSum, array, targetSum, res);
            build(current->right, currentSum, array, targetSum, res);
        }

        array.pop_back();
    }
};