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
    unordered_map<TreeNode*, int> depthCache;


    int getMaxDepth(TreeNode* node) {
        if (node == nullptr) return 0;

        if (depthCache.contains(node)) return depthCache[node];

        return (depthCache[node] = max(1 + getMaxDepth(node->left),
            1 + getMaxDepth(node->right)));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> toVisit;

        toVisit.push(root);

        while (!toVisit.empty()) {
            TreeNode* currentNode = toVisit.front();
            toVisit.pop();

            int leftDepth = getMaxDepth(currentNode->left);
            int rightDepth = getMaxDepth(currentNode->right);

            if (abs(leftDepth - rightDepth) > 1) return false;

            if (currentNode->left != nullptr) toVisit.push(currentNode->left);
            if (currentNode->right != nullptr) toVisit.push(currentNode->right);
        }

        return true;

    }
};