class Solution {
public:
int helper(vector<int>&nums , int ind  ,vector<int>&dp)
{
     if(ind==0) return nums[0] ;
    
        if(ind<01) return 0;
        if(dp[ind] != -1) return  dp[ind];
        int pick = nums[ind] +helper(nums , ind-2 , dp);
        int notpick = 0  + helper(nums , ind-1,dp);
        return dp[ind] = max(pick , notpick);

        
}
    int rob(vector<int>& nums) {
       int n  =nums.size();
       vector<int>dp(n, -1);
       return helper(nums , n-1 , dp);

        
    }
};