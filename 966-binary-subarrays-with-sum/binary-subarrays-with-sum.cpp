class Solution {
public:
int countmost(vector<int>&nums, int goal)
{
    if(goal<0) return 0;
    int n= nums.size();
    int sum = 0,cnt=0;
    int l = 0, r = 0 ;
    while(r<n)
    {
        sum += nums[r];
        while(sum > goal && l < n)
        {
            sum -= nums[l];
            l++;
        }
        cnt += r-l+1;
        r++;
    }
    return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return  countmost(nums,  goal)-countmost(nums,  goal-1);

        
    }
};