class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlen = 0, zeroes = 0;
        int l = 0;

        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] == 0) zeroes++;

            while(zeroes > 1) {  // maintain at most 1 zero in the window
                if(nums[l] == 0) zeroes--;
                l++;
            }

            // r - l + 1 is current window length including at most 1 zero
            maxlen = max(maxlen, r - l);  // subtract 1 zero we will delete
        }

        return maxlen;
    }
};
