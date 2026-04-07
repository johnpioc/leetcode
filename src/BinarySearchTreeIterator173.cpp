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
class BSTIterator {
private:
    deque<int> q_;

    void inOrderTraversal(TreeNode* node) {
        if (!node) return;

        inOrderTraversal(node->left);
        q_.push_back(node->val);
        inOrderTraversal(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inOrderTraversal(root);
    }
    
    int next() {
        int returnVal = q_.front();
        q_.pop_front();
        return returnVal;
    }
    
    bool hasNext() {
        return !q_.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
