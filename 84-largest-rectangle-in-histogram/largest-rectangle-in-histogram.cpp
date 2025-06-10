class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int maxarea = 0;

        for (int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : arr[i]; // Sentinel 0 at the end

            while (!st.empty() && arr[st.top()] > curr) {
                int element = arr[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxarea = max(maxarea, element * (nse - pse - 1));
            }

            st.push(i);
        }

        return maxarea;
    }
};
