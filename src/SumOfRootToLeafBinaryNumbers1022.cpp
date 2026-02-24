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
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return root->val;
        int sum = 0;

        explore(root->val, root->left, sum);
        explore(root->val, root->right, sum);

        return sum;
    }

    void explore(int currentNum, TreeNode* current, int& sum) {
        if (current == nullptr) return;

        currentNum = currentNum << 1;
        currentNum += current->val;

        if (current->left == nullptr && current->right == nullptr) {
            sum += currentNum;
        } else {
            explore(currentNum, current->left, sum);
            explore(currentNum, current->right, sum);
        }
    }
};