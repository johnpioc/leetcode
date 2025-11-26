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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p != nullptr && q == nullptr) return false;
        if (p == nullptr && q != nullptr) return false;
        if (p->val != q->val) return false;

        queue<TreeNode*> queueP;
        queue<TreeNode*> queueQ;

        queueP.push(p);
        queueQ.push(q);

        while (!queueP.empty() && !queueQ.empty()) {
            int pNumToVisit = queueP.size();
            int qNumToVisit = queueQ.size();

            if (pNumToVisit != qNumToVisit) return false;

            for (int i = 0; i < pNumToVisit; i++) {
                TreeNode* pCurrent = queueP.front();
                queueP.pop();

                TreeNode* qCurrent = queueQ.front();
                queueQ.pop();

                // Check neighbours and see if they line up
                if (pCurrent->left != nullptr && qCurrent->left == nullptr) return false;
                if (pCurrent->left == nullptr && qCurrent->left != nullptr) return false;
                if (pCurrent->right != nullptr && qCurrent->right == nullptr) return false;
                if (pCurrent->right == nullptr && qCurrent->right != nullptr) return false;

                if (pCurrent->left != nullptr && qCurrent->left != nullptr) {
                    if (pCurrent->left->val != qCurrent->left->val) return false;
                    else {
                        queueP.push(pCurrent->left);
                        queueQ.push(qCurrent->left);
                    }
                }

                if (pCurrent->right != nullptr && qCurrent->right != nullptr) {
                    if (pCurrent->right->val != qCurrent->right->val) return false;
                    else {
                        queueP.push(pCurrent->right);
                        queueQ.push(qCurrent->right);
                    }
                }
            }
        }

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> toVisit;
        toVisit.push(root);

        while (!toVisit.empty()) {
            TreeNode* currentNode = toVisit.front();
            toVisit.pop();

            if (currentNode->val == subRoot->val) {
                if (isSameTree(currentNode, subRoot)) return true;
            }

            if (currentNode->left != nullptr) toVisit.push(currentNode->left);
            if (currentNode->right != nullptr) toVisit.push(currentNode->right);
        }

        return false;
    }
};