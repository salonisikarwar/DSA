class Solution {
public:
    int f(int ind, int T, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (T % nums[0] == 0) return T / nums[0];
            return 1e9; // Cannot form T using only nums[0]
        }
        if (dp[ind][T] != -1) return dp[ind][T];

        int notTake = f(ind - 1, T, nums, dp);
        int take = INT_MAX;
        if (nums[ind] <= T) take = 1 + f(ind, T - nums[ind], nums, dp);

        return dp[ind][T] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
for (int T = 0; T <= amount; T++)
       {
        if(T% coins[0]==0)dp[0][T]= T/coins[0];
        else dp[0][T] = 1e9;
       }
       for(int ind  = 1 ;ind<n ;ind++)
       {
        for(int target = 0 ;target<=amount;target++)
        {
            int notTake = 0+dp[ind-1][target];
            int take = INT_MAX;
            if(coins[ind] <= target) {take  = 1+ dp[ind][target- coins[ind]];

        }
        dp[ind][target] = min (take , notTake);
       }
       }
       int ans = dp[n-1][amount];
       if(ans >= 1e9)return -1;
       return ans;

    }
};
