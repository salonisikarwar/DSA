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
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (!s2.empty()) {
            int topVal = s2.top();
            s2.pop();
            return topVal;
        }

        return -1; // Queue is empty
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (!s2.empty()) {
            return s2.top();
        }

        return -1; // Queue is empty
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};
