struct Node {
private:
    int key_;
    int value_;
    Node* next_;
    Node* prev_;

public:
    Node(int key, int value) {
        this->key_ = key;
        this->value_ = value;
        this->next_ = nullptr;
        this->prev_ = nullptr;
    };

    Node* getNext() { return this->next_; }
    void setNext(Node* next) { this->next_ = next; }

    Node* getPrev() { return this->prev_; }
    void setPrev(Node* prev) { this->prev_ = prev; }

    int getKey() { return this->key_; }
    void setKey(int key) { this->key_ = key; }

    int getValue() { return this->value_; }
    void setValue(int value) { this->value_ = value; }   
};

class LRUCache {
public:
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    int size_;
    int capacity_;

    void removeNode(Node* node) {
        if (node->getPrev() != nullptr) {
            node->getPrev()->setNext(node->getNext());
        } else {
            this->head = node->getNext();
        }

        if (node->getNext() != nullptr) {
            node->getNext()->setPrev(node->getPrev());
        } else {
            this->tail = node->getPrev();
        }
    }

    void addToHead(Node* node) {
        node->setPrev(nullptr);
        node->setNext(this->head);
        
        if (this->head != nullptr) {
            this->head->setPrev(node);
        }
        this->head = node;

        if (this->tail == nullptr) {
            this->tail = node;
        }
    }

    LRUCache(int capacity) {
        this->capacity_ = capacity;
        head = nullptr;
        tail = nullptr;
        this->size_ = 0;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            Node* entry = cache[key];
            int resultValue = entry->getValue();

            if (entry != this->head) {
                removeNode(entry); 
                addToHead(entry); 
            }
            
            return resultValue;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            Node* entry = cache[key];
            entry->setValue(value);
            
            if (entry != this->head) {
                removeNode(entry); 
                addToHead(entry);  
            }

        } else {
            Node* newEntry = new Node(key, value);
            
            addToHead(newEntry);
            cache[key] = newEntry;
            this->size_++;

            if (this->size_ > this->capacity_) {
                Node* removed = this->tail;
                removeNode(removed);
                cache.erase(removed->getKey());
                delete removed;
                this->size_--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */