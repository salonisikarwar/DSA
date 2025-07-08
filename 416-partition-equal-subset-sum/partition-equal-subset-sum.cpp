class Solution {
public:
 bool subsetSumToK(int n, int k, vector<int>& arr) {
        // Base DP arrays (only 2 rows to save space)
        vector<bool> prev(k + 1, false), cur(k + 1, false);

        // Always possible to make sum 0 (empty subset)
        prev[0] = cur[0] = true;

        // If first element fits in sum range
        if (arr[0] <= k)
            prev[arr[0]] = true;

        // Loop through the rest of the elements
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;

                if (arr[ind] <= target)
                    take = prev[target - arr[ind]];

                cur[target] = take || notTake;
            }
            prev = cur; // Move to the next row
        }

        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
         int totalsum = 0;
         int n =nums.size();
         for(int i = 0 ;i<n;i++)
         {
            totalsum += nums[i];
         }
         if(totalsum%2)return false;
         int target  = totalsum/2;
         return subsetSumToK(n, target,nums);
    }
};