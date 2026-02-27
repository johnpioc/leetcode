class MyCircularQueue {
private:
    vector<int> buffer_;
    int bufferSize_;
    int backIndex_;
    int frontIndex_;

    int getIndex(int index) { return index % this->bufferSize_; }
public:
    MyCircularQueue(int k) {
        this->bufferSize_ = k;
        this->backIndex_ = this->frontIndex_ = 0;
        this->buffer_.reserve(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        buffer_[this->getIndex(this->backIndex_)] = value;
        this->backIndex_++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        this->frontIndex_++;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : this->buffer_[getIndex(this->frontIndex_)];
    }
    
    int Rear() {
        return isEmpty() ? -1 : this->buffer_[getIndex(this->backIndex_ - 1)];
    }
    
    bool isEmpty() {
        return this->backIndex_ == this->frontIndex_;
    }
    
    bool isFull() {
        return this->backIndex_ - this->frontIndex_ >= this->bufferSize_;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */