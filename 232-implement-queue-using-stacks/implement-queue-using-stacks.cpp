#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {
        // Nothing to initialize manually
    }

    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into empty s1
        s1.push(x);

        // Move everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek() {
        if (s1.empty()) return -1;
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};
