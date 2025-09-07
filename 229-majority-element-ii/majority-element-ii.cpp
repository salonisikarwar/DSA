class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n =nums.size();
        
    vector<int>ls; 
        map<int,int>mpp;
        int min=floor(n/3)+1;
        for(int i =0;i<n;i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]]==min)
            ls.push_back(nums[i]);
        }
        return ls;
    }
};