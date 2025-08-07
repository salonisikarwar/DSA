class Solution {
public:
 int helper(int ind , vector<int>&dp)
 {
    if(ind==0)return 1 ;
    if(ind==1)return 1;
    if(dp[ind] != -1)return dp[ind];
      dp[ind]  = helper(ind-1 ,dp) +helper(ind-2 , dp);
        return dp[ind] ;
 }
    int climbStairs(int n) {
    vector<int>dp(n+1, -1);
   return  helper(n , dp);}
    
    
};