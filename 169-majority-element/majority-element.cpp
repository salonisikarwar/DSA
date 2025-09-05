class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cnt = 0;
int ele;
for(int i = 0; i < nums.size(); i++) {
    if (cnt == 0) {      // no current candidate
        cnt = 1;
        ele = nums[i];   // choose new candidate
    }
    else if (nums[i] == ele) {
        cnt++;           // same as candidate → increase count
    }
    else {
        cnt--;           // different → cancel out one occurrence
    }
}



int cnt1 = 0;
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == ele) {
        cnt1++;
    }
}
return ele;

    }
};