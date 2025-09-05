class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: create hash array of size n+1
        vector<int> hash(n+1, 0);

        // Step 2: mark the numbers present
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = 1;
        }

        // Step 3: find the missing number
        for (int i = 0; i <= n; i++) {
            if (hash[i] == 0) {
                return i;
            }
        }

        return -1; // should never reach here
    }
};
