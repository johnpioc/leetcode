class MedianFinder {
public:
    priority_queue<int> bottomHalf;
    priority_queue<int, vector<int>, greater<int>> topHalf;

    MedianFinder() {}

    void addNum(int num) {
        if (bottomHalf.empty() || num <= bottomHalf.top())
            bottomHalf.push(num);
        else
            topHalf.push(num);

        if (bottomHalf.size() > topHalf.size() + 1) {
            topHalf.push(bottomHalf.top());
            bottomHalf.pop();
        } else if (topHalf.size() > bottomHalf.size() + 1) {
            bottomHalf.push(topHalf.top());
            topHalf.pop();
        }
    }
    
    double findMedian() {
        if (bottomHalf.empty() && topHalf.empty()) return 0.0;

        if (bottomHalf.size() > topHalf.size())
            return bottomHalf.top();
        else if (topHalf.size() > bottomHalf.size())
            return topHalf.top();
        else
            return (bottomHalf.top() + topHalf.top()) / 2.0;
    }
};