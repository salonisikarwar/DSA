class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n  = nums.size();
        vector<int>ls;
        for(int i = 0;i<n;i++)
        {
                    int cnt  = 0;

            if(ls.size() == 0|| ls[0] != nums[i])
            for(int j = 0 ;j<n;j++)
            {
                if(nums[i] == nums[j])
                cnt++;
            }
                    if(cnt > n/3){
                        ls.push_back(nums[i]);
                    }
                    if(ls.size() == 2)
                    break;

        }
        return ls;
        
        
    }
};