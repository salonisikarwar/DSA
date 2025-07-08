class Solution {
public:
 bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
             int n = arr.size();

vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for(int i =0 ;i<n;i++){dp[i][0] = true;
        }
         if (arr[0] <= sum)
            dp[0][arr[0]] = true;
        
        for(int ind =1;ind<=n-1 ;ind++)
        {
            for(int target =1 ;target<= sum;target++)
            {
                bool nottake =dp[ind-1] [target ];
            bool take = false;
            if(target>= arr[ind])
      {
          take = dp[ind-1][ target - arr[ind]];
          
      }
      dp[ind][target] = take || nottake;
                
            }
        }
                return dp[n - 1][sum];

    }

    bool canPartition(vector<int>& nums) {
         int totalsum = 0;
         for(int i = 0 ;i<nums.size();i++)
         {
            totalsum += nums[i];
         }
         if(totalsum%2)return false;
         int target  = totalsum/2;
         return isSubsetSum(nums, target);
    }
};