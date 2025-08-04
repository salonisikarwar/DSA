class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        string LPS = "";

        for (int i = 0; i < s.length(); i++) {
            // Odd length palindrome
            int low = i, high = i;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                if ((high - low + 1) > LPS.length()) {
                    LPS = s.substr(low, high - low + 1);
                }
                low--;
                high++;
            }

            // Even length palindrome
            low = i, high = i + 1;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                if ((high - low + 1) > LPS.length()) {
                    LPS = s.substr(low, high - low + 1);
                }
                low--;
                high++;
            }
        }

        return LPS;
    }
};
