class Solution {
public:
    

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
       vector<int> prev(amount + 1, 0);
       vector<int> curr(amount + 1, 0);

       
for (int T = 0; T <= amount; T++)
       {
        if(T% coins[0]==0)prev[T]= T/coins[0];
        else prev[T] = 1e9;
       }
       for(int ind  = 1 ;ind<n ;ind++)
       {
        for(int target = 0 ;target<=amount;target++)
        {
            int notTake = 0+prev[target];
            int take = INT_MAX;
            if(coins[ind] <= target) {take  = 1+ curr[target- coins[ind]];

        }
        curr[target] = min (take , notTake);
       }
       prev  = curr;
       }
       int ans = prev[amount];
       if(ans >= 1e9)return -1;
       return ans;

    }
};
