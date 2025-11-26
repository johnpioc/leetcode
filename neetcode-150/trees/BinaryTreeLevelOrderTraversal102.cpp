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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr){
            vector<vector<int>> output;
            return output;
        }

        queue<TreeNode*> toVisit;
        vector<vector<int>> output;

        toVisit.push(root);
        while (!toVisit.empty()) {
            int numToVisit = toVisit.size();

            vector<int> level;
            for (int i = 0; i < numToVisit; i++) {
                TreeNode* currentNode = toVisit.front();
                toVisit.pop();

                level.push_back(currentNode->val);

                if (currentNode->left != nullptr) toVisit.push(currentNode->left);
                if (currentNode->right != nullptr) toVisit.push(currentNode->right);
            }

            output.push_back(level);
        }

        return output;
    }
};