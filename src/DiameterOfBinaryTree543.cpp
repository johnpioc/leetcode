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
    unordered_map<TreeNode*, int> heights;

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        return max({ 
            getHeight(root->left) + getHeight(root->right),
            diameterOfBinaryTree(root->left),
            diameterOfBinaryTree(root->right)
        });
    }

    int getHeight(TreeNode* current) {
        if (current == nullptr)
            return 0;
        
        return heights[current] = 1 + max(getHeight(current->left), getHeight(current->right));
    }
};