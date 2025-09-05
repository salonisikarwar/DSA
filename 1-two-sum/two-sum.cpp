class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            
            // check if complement is already seen
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            
            // store current number with index
            mp[nums[i]] = i;
        }
        
        return {};
    }
};
