/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        deque<Node*> toSearch;
        toSearch.push_back(root);

        while (!toSearch.empty()) {
            int n = toSearch.size();
            Node* prev = nullptr;

            for (int i = 0; i < n; i++) {
                Node* curr = toSearch.front();
                toSearch.pop_front();

                if (!prev) prev = curr;
                else {
                    prev->next = curr;
                    prev = curr;
                }

                if (curr->left) toSearch.push_back(curr->left);
                if (curr->right) toSearch.push_back(curr->right);
            }

            prev->next = nullptr;
        }

        return root;
    }
};