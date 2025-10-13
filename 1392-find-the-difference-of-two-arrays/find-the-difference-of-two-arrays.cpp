class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int> freq1,freq2;
        for(auto x : nums1)
        {
            freq1[x]++;
        }
        for(auto x : nums2)
        {
            freq2[x]++;
        }
        vector<int> v1;
        vector<int> v2;
        for(auto x : nums1)
        {
            if(freq2.count(x)==0 && find(v1.begin(),v1.end(),x)==v1.end()) v1.push_back(x);
        }
        for(auto x : nums2)
        {
            if(freq1.count(x)==0 && find(v2.begin(),v2.end(),x)==v2.end()) v2.push_back(x);
        }
        return {v1,v2};
    }
};