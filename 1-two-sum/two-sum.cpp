class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int , int>numsMap;
      int n  = nums.size();
      for(int i  = 0 ;i<n ; i++)
      {
        numsMap[nums[i]]= i;
              }
for(int i  = 0 ;i< n ;i++){
int complement = target - nums[i];
if(numsMap.count(complement) && numsMap[complement]!= i)
{

    return{i , numsMap[complement]};
}
}
      return {};
    }

};