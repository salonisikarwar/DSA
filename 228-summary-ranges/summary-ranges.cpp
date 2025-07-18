class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        int i = 0;
        
        while (i < n) {
            int start = nums[i];
            // keep moving forward while consecutive numbers
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            int end = nums[i];
            
            if (start == end) {
                res.push_back(to_string(start));
            } else {
                res.push_back(to_string(start) + "->" + to_string(end));
            }
            i++;
        }
        
        return res;
        
    }
};