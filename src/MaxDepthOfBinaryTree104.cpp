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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> toVisit;
        toVisit.push(root);

        int numOfLevels = 0;
        while (!toVisit.empty()) {
            int numToVisit = toVisit.size();
            numOfLevels++;

            for (int i = 0; i < numToVisit; i++) {
                TreeNode* currentNode = toVisit.front();
                toVisit.pop();

                if (currentNode->left != nullptr) {
                    toVisit.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    toVisit.push(currentNode->right);
                }
            }
        }

        return numOfLevels;
    }
};