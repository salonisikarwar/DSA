class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int maxlen = 0;
        int n = fruits.size();
        int l =0, r = 0;
        map<int, int>mpp;
        while(r< n)
        {mpp[fruits[r]]++;
        if(mpp.size() > 2)
        {
            
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)
                mpp.erase(fruits[l]);
                l++;
            

        }
        else   {
            maxlen = max(maxlen , r-l+1);
        }
        r++;
        }
        return maxlen;
        }
    
        
};