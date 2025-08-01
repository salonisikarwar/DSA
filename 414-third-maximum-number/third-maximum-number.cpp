class Solution {
public:
    int thirdMax(vector<int>& nums) {
         set<int> topThree;

        for (int num : nums) {
            topThree.insert(num);
            if (topThree.size() > 3) {
                topThree.erase(topThree.begin()); // remove the smallest
            }
        }

        // If we have 3 distinct elements, return the smallest (3rd max)
        // Otherwise, return the largest (max)
        if (topThree.size() == 3) {
            return *topThree.begin();
        } else {
            return *topThree.rbegin();
        }
    
        
    }
};