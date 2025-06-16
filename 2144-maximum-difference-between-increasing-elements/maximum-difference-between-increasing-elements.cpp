class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0];
        int max_diff = -1;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] > min_val) {
                max_diff = max(max_diff, nums[j] - min_val);
            } else {
                min_val = nums[j];
            }
        }

        return max_diff;
    }
        
    
};