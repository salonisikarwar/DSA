class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;  // Map from element to its next greater
        stack<int> st;

        // Process nums2 to build the nextGreater map
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

            if (st.empty()) {
                nextGreater[num] = -1;
            } else {
                nextGreater[num] = st.top();
            }

            st.push(num);
        }

        // Build the result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};
