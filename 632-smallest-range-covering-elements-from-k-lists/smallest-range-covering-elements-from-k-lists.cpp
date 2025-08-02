class node {
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node*, vector<node*>, compare> minHeap;

        // Initialize heap
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i][0];
            mini = min(mini, val);
            maxi = max(maxi, val);
            minHeap.push(new node(val, i, 0));
        }

        int start = mini, end = maxi;

        while (!minHeap.empty()) {
            node* temp = minHeap.top();
            minHeap.pop();

            mini = temp->data;

            // Update range if smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // If next element in the same row exists
            if (temp->col + 1 < nums[temp->row].size()) {
                int nextVal = nums[temp->row][temp->col + 1];
                maxi = max(maxi, nextVal);
                minHeap.push(new node(nextVal, temp->row, temp->col + 1));
            } else {
                break; // We can't cover all lists anymore
            }
        }

        return {start, end};
    }
};
