#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;  // Declare q as a member variable

public:
    MyStack() {
        // No need to initialize q here again
    }

    void push(int x) {
        q.push(x);
        int s = q.size();
        for (int i = 1; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
