class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        if (n == 0) return "";

        vector<int> lps(n, 0);  // prefix table
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // fallback
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // lps[n-1] stores the length of longest prefix that is also a suffix
        return s.substr(0, lps[n - 1]);
    }
};
