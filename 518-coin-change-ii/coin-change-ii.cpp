class Solution {
public: 
    int change(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int>prev(target+1,0);
        vector<int>cur(target+1,0);
        for(int t=0;t<=target;t++){
            if(t%nums[0]==0) prev[t]=1;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                long nottake=prev[t];
                long take=(nums[i]<=t)?cur[t-nums[i]]:0;
                cur[t] = nottake + take;
            }
            prev=cur;
        }
        return prev[target];
    }
};