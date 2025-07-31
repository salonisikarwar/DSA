class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap
    }
};
class Solution {
public:
   


    ListNode* mergeKLists(vector<ListNode*>& lists) {
 priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;


       int  k  = lists.size();

       //step 1:
       for(int i= 0;i<k;i++)
       {
        if(lists[i] != NULL )
        {
            minHeap.push(lists[i]);
        }
       }
       ListNode* head = NULL;
       ListNode*tail = NULL;
       
       while(!minHeap.empty())
       {
        ListNode* top  = minHeap.top();
        minHeap.pop();

        if(top->next != NULL)
        {
            minHeap.push(top->next);
        }
        if(head == NULL)
        {
            head   = top;
            tail  =top  ;
        }
            /*if(tail->next != NULL)
            {
                minHeap.push(tail->next);
            }*/
            else{
                tail->next = top ;
                tail  =top ;}

                /*if(tail->next != NULL)
                {
                    minHeap.push(tail->next);
                }
            }*/
        }
        return head;
       }
    
};
