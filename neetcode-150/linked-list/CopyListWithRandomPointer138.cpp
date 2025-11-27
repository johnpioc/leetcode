/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> originalToCopy;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) 
            return nullptr;

        Node* newHead = new Node(head->val);
        Node* currentNew = newHead;
        Node* currentOld = head->next;
        originalToCopy[head] = newHead;

        while (currentOld != nullptr) {
            Node* newNode = new Node(currentOld->val);
            originalToCopy[currentOld] = newNode;
            currentNew->next = newNode;
            currentNew = currentNew->next;
            currentOld = currentOld->next;
        }

        currentOld = head;
        while (currentOld != nullptr) {
            if (currentOld->random != nullptr) {
                originalToCopy[currentOld]->random = originalToCopy[currentOld->random];
            }
            currentOld = currentOld->next;
        }

        return newHead;
    }
};