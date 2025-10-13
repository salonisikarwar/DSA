class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0,left_sum = 0,right_sum = 0;
        for(int i = 0; i < nums.size();i++){
            total_sum += nums[i];
        }
        for(int i = 0; i < nums.size();i++){
            if(i == 0) left_sum = 0;
            else left_sum += nums[i-1];
            right_sum = total_sum - left_sum - nums[i];
            if(left_sum == right_sum) return i;
        }
        return -1;
    }
};