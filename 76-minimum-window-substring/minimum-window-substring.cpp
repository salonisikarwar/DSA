class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0, r = 0;
        int minlen = INT_MAX;
        int sindex = -1;

        int hash[256] = {0};  // frequency array
        for (int j = 0; j < m; j++) {
            hash[t[j]]++;
        }

        int cnt = 0;

        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;

            while (cnt == m) {
                if ((r - l + 1) < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }

            r++;
        }

        if (sindex == -1) return "";
        return s.substr(sindex, minlen);
    }
};