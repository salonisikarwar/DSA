class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int len = 0;
        int maxlen = 0;
        int l = 0, r = 0;
        int hash[256];
        fill(hash, hash + 256, -1);

        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                // move left pointer before overwriting hash
                l = hash[s[r]] + 1;
            }
            // update last index of current char
            hash[s[r]] = r;

            len = r - l + 1;
            maxlen = max(maxlen, len);

            r++;
        }
        return maxlen;
    }
};
