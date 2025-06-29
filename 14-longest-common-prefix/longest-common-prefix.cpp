class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Iterate over characters of the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];

            // Check current character against all other strings
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);  // mismatch found
                }
            }
        }

        return strs[0];  // all characters matched
    }
};
