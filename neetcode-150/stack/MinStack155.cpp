class MinStack {
public:
    // Index 0: value, Index 1: Minimum at that point
    stack<array<int, 2>> minStack;
    int minimum;

    MinStack() {
        this->minimum = INT_MAX;    
    }
    
    void push(int val) {
        this->minimum = min(this->minimum, val);
        minStack.push({ val, this->minimum });
    }
    
    void pop() {
        minStack.pop();

        if (minStack.size() > 0) {
            this->minimum = minStack.top()[1];
        } else {
            this->minimum = INT_MAX;
        }
    }
    
    int top() {
        return this->minStack.top()[0];
    }
    
    int getMin() {
        return this->minStack.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */