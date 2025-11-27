#pragma once

#include <cmath>
#include <vector>
#include <unordered_map>
#include "Entry.h"

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

        K left = leftIndex(i) < this->data_.size() ? this->data_[leftIndex(i)] : NULL;
        K right = rightIndex(i) < this->data_.size() ? this->data_[rightIndex(i)] : NULL;

        if (left == NULL)
            return;

        if (right == NULL && left < current) {
            swap(i, leftIndex(i));
            downheap(leftIndex(i));
        }

        if (right != NULL) {
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
        if (this->empty()) {
            return NULL;
        }

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

    K getKey(V value) {
        if (!valueToEntryIndex_.contains(value))
            return NULL;

        int index = valueToEntryIndex_[value];

        return this.data_[index].getKey();
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
