#include <stack>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {}

    void push(int val) {
        long long v = val;
        if (st.empty()) {
            mini = v;
            st.push(v);
        } else {
            if (v >= mini) {
                st.push(v);
            } else {
                st.push(2 * v - mini);  // encode
                mini = v;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        if (top < mini) {
            mini = 2 * mini - top;  // decode
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long top = st.top();
        if (top < mini) return mini;
        return top;
    }

    int getMin() {
        return mini;
    }
};
