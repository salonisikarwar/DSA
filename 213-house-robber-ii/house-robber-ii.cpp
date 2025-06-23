class Solution {
public:
    int maximumNonAdjacentSum(vector<int>& nums) {
        int prev1 = nums[0], prev2 = 0;
        for(int i = 1; i < nums.size(); i++) {
            int take = nums[i] + prev2;
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> temp1(nums.begin() + 1, nums.end());      // Exclude first
        vector<int> temp2(nums.begin(), nums.end() - 1);      // Exclude last

        return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
    }
};
