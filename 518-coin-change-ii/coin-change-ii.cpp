class Solution {
public:
int f (int ind , int T , vector<int> &a , vector<vector<long>>& dp )
{
    if(ind ==0)
    {
        return(T % a[0] == 0);
    }
    if(dp[ind][T] != -1) return dp[ind][T];
    long long notTake = f(ind-1 , T, a , dp );
    long take = 0;
     if (T >= a[ind])
            take = f(ind, T - a[ind], a, dp);
    return  dp[ind][T] = take +notTake;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long>>dp(n ,vector<long>(amount+1 , -1));
       return f(n-1 ,amount ,  coins , dp  ) ;
    }
};