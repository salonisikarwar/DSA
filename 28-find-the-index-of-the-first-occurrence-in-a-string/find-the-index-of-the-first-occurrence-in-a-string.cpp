class Solution {

public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        if (needle.length() > haystack.length()) return -1;

        int i = 0;
        while (i <= haystack.length() - needle.length()) {
            int j = 0;

            while (j < needle.length()) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
                j++;
            }

            if (j == needle.length()) {
                return i;  // match found at index i
            }

            i++;
        }

        return -1; // no match found
    }
};


 