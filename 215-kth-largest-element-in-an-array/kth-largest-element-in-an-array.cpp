class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap using priority_queue
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();

        // Step 1: Push first k elements into min-heap
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        // Step 2: Process remaining elements
        for (int i = k; i < n; i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        // Top of min-heap is the Kth largest
        return pq.top();
    }
};
