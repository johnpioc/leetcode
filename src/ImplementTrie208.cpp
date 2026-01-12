class Trie {
private:
    struct Node {
        unordered_map<char, Node*> next;
        int instances;

        Node() {
            this->instances = 0;
        }
    };

    Node* head;
public:
    Trie() {
        this->head = new Node();
    }
    
    void insert(string word) {
        Node* current = this->head;
        for (char character : word) {
            if (!current->next.contains(character)) {
                current->next[character] = new Node();
            }

            current = current->next[character];
        }

        current->instances++;
    }
    
    bool search(string word) {
        Node* current = this->head;

        for (char character : word) {
            if (!current->next.contains(character)) {
                return false;
            }

            current = current->next[character];
        }

        return current->instances > 0;
    }
    
    bool startsWith(string prefix) {
        Node* current = this->head;

        for (char character : prefix) {
            if (!current->next.contains(character)) {
                return false;
            }

            current = current->next[character];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */