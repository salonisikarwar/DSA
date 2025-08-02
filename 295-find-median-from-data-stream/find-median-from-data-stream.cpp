class MedianFinder {
private:
    priority_queue<int> maxHeap; // Left part (max-heap)
    priority_queue<int, vector<int>, greater<int>> minHeap; // Right part (min-heap)
    double median;

    // Signum function
    int signum(int a, int b) {
        if (a == b) return 0;
        return (a > b) ? 1 : -1;
    }

    // This is your logic, adapted for streaming
    void callMedian(int num) {
        switch (signum(maxHeap.size(), minHeap.size())) {
            case 0: // Both heaps equal
                if (num <= median) {
                    maxHeap.push(num);
                    median = maxHeap.top();
                } else {
                    minHeap.push(num);
                    median = minHeap.top();
                }
                break;

            case 1: // maxHeap has more elements
                if (num <= median) {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(num);
                } else {
                    minHeap.push(num);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
                break;

            case -1: // minHeap has more elements
                if (num <= median) {
                    maxHeap.push(num);
                } else {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(num);
                }
                median = (maxHeap.top() + minHeap.top()) / 2.0;
                break;
        }
    }

public:
    MedianFinder() {
        median = 0;
    }

    void addNum(int num) {
        callMedian(num);  // your logic here
    }

    double findMedian() {
        return median;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */