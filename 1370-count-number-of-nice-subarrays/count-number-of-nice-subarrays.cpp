class Solution {
public:
int countatmost(vector<int>&nums , int goal )
{
            int l =0  ,r =0 , sum = 0, cnt = 0;
            while(r<nums.size()){
            sum += nums[r]%2;
            while(sum>goal)
            {
                sum -= nums[l]%2;
                l++;

            }
            cnt += (r-l+1);
            r++;

}
return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {

return countatmost(nums , k) - countatmost(nums, k-1);

        
    }
};