class StockSpanner {
public:
    stack<pair<int, int>> st; // stores {price, index}
    int index;

    StockSpanner() {
        index = -1;
    }

    int next(int price) {
        index++; // Move to next index
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int span;
        if (st.empty()) {
            span = index + 1;
        } else {
            span = index - st.top().second;
        }

        st.push({price, index});
        return span;
    }
};
