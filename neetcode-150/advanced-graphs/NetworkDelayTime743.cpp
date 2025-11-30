template <typename K, typename V>
struct Entry {
private:
    K key_;
    V value_;

public:
    Entry(K key, V value) {
        this->key_ = key;
        this->value_ = value;
    }

    K getKey() { return this->key_; }
    void setKey(K key) { this->key_ = key; }

    V getValue() { return this->value_; }
    void setValue(V value) { this->value_ = value; }

    bool operator<(const Entry<K, V>& other) { return this->key_ < other.key_; }
    bool operator>(const Entry<K, V>& other) { return this->key_ > other.key_; }
    bool operator<=(const Entry<K, V>& other) { return this->key_ <= other.key_; }
    bool operator>=(const Entry<K, V>& other) { return this->key_ >= other.key_; }
    bool operator==(const Entry<K, V>& other) { return this->key_ == other.key_; }
    bool operator!=(const Entry<K,V>& other) { return this->key_ != other.key_; }
};

template <typename K, typename V>
struct AdaptablePriorityQueue {
private:
    std::vector<Entry<K,V>> data_;
    std::unordered_map<V, int> valueToEntryIndex_;

    int parentIndex(int i) { return i != 0 ? std::floor((i - 1) / 2.0) : 0; }
    int leftIndex(int i) { return 2 * i + 1; }
    int rightIndex(int i) { return 2 * i + 2; }

    void swap(int indexA, int indexB) {
        Entry<K,V> temp = this->data_[indexA];
        this->data_[indexA] = this->data_[indexB];
        this->data_[indexB] = temp;

        valueToEntryIndex_[this->data_[indexA].getValue()] = indexA;
        valueToEntryIndex_[this->data_[indexB].getValue()] = indexB;
    }

    void upheap(int i) {
        int currentIndex = i;
        int currentParentIndex = parentIndex(i);

        while (currentParentIndex != 0 
            && this->data_[currentIndex] < this->data_[currentParentIndex]) {
            swap(currentIndex, currentParentIndex);

            currentIndex = currentParentIndex;
            currentParentIndex = parentIndex(currentIndex);
        }

        if (this->data_[currentIndex] < this->data_[currentParentIndex]) {
            swap(currentIndex, currentParentIndex);
        }
    }

    void downheap(int i) {
        K current = this->data_[i].getKey();

        bool leftExists = leftIndex(i) < this->data_.size();
        bool rightExists = rightIndex(i) < this->data_.size();

        if (!leftExists)
            return;

        K left = this->data_[leftIndex(i)].getKey();

        if (!rightExists && left < current) {
            swap(i, leftIndex(i));
            downheap(leftIndex(i));
        }

        if (rightExists) {
            K right = this->data_[rightIndex(i)].getKey();
            if (left < current && right < current) {
                if (left <= right) {
                    swap(i, leftIndex(i));
                    downheap(leftIndex(i));
                } else {
                    swap(i, rightIndex(i));
                    downheap(rightIndex(i));
                }
            } else if (left < current && right >= current) {
                swap(i, leftIndex(i));
                downheap(leftIndex(i));
            } else if (left >= current && right < current) {
                swap(i, rightIndex(i));
                downheap(rightIndex(i));
            }
        }
    }

public:
    AdaptablePriorityQueue() {}

    int size() { return this->data_.size(); }
    bool empty() { return this->data_.size() == 0; }

    void insert(Entry<K,V> entry) {
        this->data_.push_back(entry);
        valueToEntryIndex_[entry.getValue()] = this->size() - 1;
        upheap(this->size() - 1);
    }

    void insert(K key, V value) {
        insert(Entry<K,V>(key, value));
    }

    Entry<K,V> removeMin() {
        Entry<K,V> min = this->data_[0];
        swap(0, this->size() - 1);
        this->data_.pop_back();
        valueToEntryIndex_.erase(min.getValue());

        if (this->size() > 0) {
            downheap(0);
        }

        return min;
    }

    Entry<K,V> peekMin() { return this->empty() ? NULL : this->data_[0]; }
    void clear() { this->data_.clear(); }

    bool containsValue(V value) {
        return valueToEntryIndex_.contains(value);
    }

    K getKey(V value) {
        int index = valueToEntryIndex_[value];
        return this->data_[index].getKey();
    }

    void decreaseKey(V value, K newKey) {
        if (!valueToEntryIndex_.contains(value)) {
            return;
        }

        int index = valueToEntryIndex_[value];
        this->data_[index].setKey(newKey);
        upheap(index);
    }
};

class Solution {    
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<vector<int>>> adj;

        for (vector<int> time : times) {
            adj[time[0]].push_back(time);
        }

        AdaptablePriorityQueue<int, int> apq;

        for (int i = 1; i <= n; i++) {
            apq.insert(i == k ? 0 : INT_MAX, i);
        }

        int maxDistance = 0;
        while (!apq.empty()) {
            Entry<int, int> current = apq.removeMin();
            int u = current.getValue();
            int w = current.getKey();

            if (w == INT_MAX) {
                return -1;
            }

            maxDistance = max(w, maxDistance);

            for (vector<int> edge : adj[u]) {
                int v = edge[1];
                int newDistance = w + edge[2];
                if (apq.containsValue(v) && newDistance < apq.getKey(v)) {
                    apq.decreaseKey(v, newDistance);
                }
            }
        }

        return maxDistance;
    }
};