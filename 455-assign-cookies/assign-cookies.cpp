class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int r = 0, l = 0;

        sort(g.begin(), g.end());  // greed factors
        sort(s.begin(), s.end());  // cookie sizes

        while (l < m && r < n) {  // important: check both bounds
            if (g[r] <= s[l]) {
                r++;
            }
            l++;
        }

        return r;
    }
};
