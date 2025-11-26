/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<int, Node*> clones;
        set<int> visitedValues;

        stack<Node*> toVisit;

        toVisit.push(node);
        visitedValues.insert(node->val);
        clones[node->val] = new Node();

        while (!toVisit.empty()) {
            // 1. Unpack current node from stack
            Node* currentNode = toVisit.top();
            toVisit.pop();

            // 2. insert value into clone
            clones[currentNode->val]->val = currentNode->val;

            // 3. Go through each neighbour, and add them to toVisit provided we haven't visited
            // them already.
            for (Node* neighbour : currentNode->neighbors) {
                if (!visitedValues.contains(neighbour->val)) {
                    clones[neighbour->val] = new Node();
                    visitedValues.insert(neighbour->val);
                    toVisit.push(neighbour);
                }

                clones[currentNode->val]->neighbors.push_back(clones[neighbour->val]);
            }
        }

        return clones[node->val];
    }
};