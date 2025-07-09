class Solution {
public:
    int f(int ind, int sum, vector<int>& num, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (sum == 0 && num[0] == 0) return 2;   // both +0 and -0 are valid
            if (sum == 0 || sum == num[0]) return 1;
            return 0;
        }
        if (dp[ind][sum] != -1) return dp[ind][sum];

        int notTake = f(ind - 1, sum, num, dp);
        int take = 0;
        if (num[ind] <= sum)
            take = f(ind - 1, sum - num[ind], num, dp);

        return dp[ind][sum] = notTake + take;
    }

    int findWays(vector<int>& num, int target) {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, num, dp);
    }

    int countPartitions(vector<int>& arr, int d) {
        int totalSum = 0;
        for (auto it : arr) totalSum += it;

        // Check if we can form such a subset
        if (totalSum - d < 0 || (totalSum - d) % 2 != 0) return 0;

        int target = (totalSum - d) / 2;
        return findWays(arr, target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target); 
    }
};
