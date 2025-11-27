#pragma once

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
    K setKey(K key) { this->key_ = key; }

    V getValue() { return this->value_; }
    V setValue(V value) { this->value_ = value; }

    bool operator<(const Entry<K, V>& other) { return this->key_ < other.key_; }
    bool operator>(const Entry<K, V>& other) { return this->key_ > other.key_; }
    bool operator<=(const Entry<K, V>& other) { return this->key_ <= other.key_; }
    bool operator>=(const Entry<K, V>& other) { return this->key_ >= other.key_; }
    bool operator==(const Entry<K, V>& other) { return this->key_ == other.key_; }
    bool operator!=(const Entry<K,V>& other) { return this->key_ != other.key_; }
};
