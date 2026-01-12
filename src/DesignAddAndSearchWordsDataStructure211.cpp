class WordDictionary {
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
    WordDictionary() {
        this->head = new Node();
    }
    
    void addWord(string word) {
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
        return search(word, this->head, 0);
    }

    bool search(string word, Node* current, int index) {
        if (index == word.size()) {
            return current->instances > 0;
        }

        char currentChar = word[index];

        if (currentChar == '.') {
            for (const auto& [key, value]: current->next) {
                if (search(word, value, index + 1))
                    return true;
            }

            return false;
        } else {
            if (!current->next.contains(currentChar)) {
                return false;
            }

            return search(word, current->next[currentChar], index + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */