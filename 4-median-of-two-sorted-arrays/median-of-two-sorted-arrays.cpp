class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n= nums2.size();
        int left = m-1;
        int right = 0;
        while(left>=0 && right<n)
         {
            if(nums1[left]>nums2[right])
            {
                swap(nums1[left] , nums2[right]);
                left--;
                right++;
            }
            else
            break;
         }
         sort(nums1.begin() , nums1.begin()+m);
         sort(nums2.begin() , nums2.end());
        nums1.resize(m + n);

         for(int i = 0;i<n;i++)
         {
            nums1[m+i] = nums2[i];
         }

        
    
        
          int total = m + n;
        if (total % 2 == 1) {
            return nums1[total / 2];
        } else {
            return (nums1[total / 2 - 1] + nums1[total / 2]) / 2.0;
        }

    }
};