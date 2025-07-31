class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Push head of each list into the heap
        for (auto l : lists) {
            if (l) pq.push(l);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (!pq.empty()) {
            ListNode* curr = pq.top(); pq.pop();
            tail->next = curr;
            tail = tail->next;
            if (curr->next) {
                pq.push(curr->next);
            }
        }
        
        return dummy.next;
    }
};