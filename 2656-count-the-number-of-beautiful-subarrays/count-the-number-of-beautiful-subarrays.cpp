class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long cnt = 0;
        int xr = 0;
        unordered_map<int, long long> mpp;
        mpp[0] = 1;  // prefix XOR = 0 initially
        
        for (int i = 0; i < nums.size(); i++) {
            xr ^= nums[i];  // update prefix XOR
            
            // if xr was seen before, all those subarrays form XOR=0 with current prefix
            cnt += mpp[xr];
            
            // store this prefix XOR
            mpp[xr]++;
        }
        
        return cnt;
    }
};
