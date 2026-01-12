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
    void postOrder(TreeNode* node, int currentHighest, vector<int>* output) {
        if (node->val >= currentHighest) {
            cout << "Good node:" << node->val << endl;
            (*output).push_back(node->val);
        }

        if (node->left != nullptr) {
            postOrder(node->left, max(currentHighest, node->val), output);
        }

        if (node->right != nullptr) {
            postOrder(node->right, max(currentHighest, node->val), output);
        }
    }

    int goodNodes(TreeNode* root) {
        vector<int> output;

        postOrder(root, root->val, &output);
        return output.size();
    }
};