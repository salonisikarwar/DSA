class Solution {
public:
    struct Node {
        int val, row, col;
        Node(int v, int r, int c) : val(v), row(r), col(c) {}
    };

    struct compare {
        bool operator()(const Node& a, const Node& b) {
            return a.val > b.val; // min-heap
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int rangeStart = 0, rangeEnd = INT_MAX;
        int currentMax = INT_MIN;

        // Use value-based heap (no pointers or dynamic memory)
        priority_queue<Node, vector<Node>, compare> minHeap;

        // Initialize heap with first elements of all lists
        for (int i = 0; i < k; ++i) {
            int val = nums[i][0];
            minHeap.emplace(val, i, 0);
            currentMax = max(currentMax, val);
        }

        while (true) {
            Node current = minHeap.top(); minHeap.pop();
            int currentMin = current.val;

            // Update range if smaller
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }

            // If there's a next element in the same list, push it
            if (current.col + 1 < nums[current.row].size()) {
                int nextVal = nums[current.row][current.col + 1];
                currentMax = max(currentMax, nextVal);
                minHeap.emplace(nextVal, current.row, current.col + 1);
            } else {
                // One list is exhausted — we can't include all lists anymore
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};
