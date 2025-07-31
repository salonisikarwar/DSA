class Solution {
public:
    // Max-heapify
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        // Step 1: Extract all node values into the vector
        for (auto list : lists) {
            while (list != nullptr) {
                values.push_back(list->val);
                list = list->next;
            }
        }

        // Step 2: Build max heap
        int n = values.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(values, n, i);
        }

        // Step 3: Heap sort to get sorted values in ascending order
        for (int i = n - 1; i > 0; i--) {
            swap(values[0], values[i]);
            heapify(values, i, 0); // reduce size
        }

        // Step 4: Create new linked list from sorted values
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (int val : values) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy->next;
    }
};
