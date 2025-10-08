class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();
        
        while (i < n) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }
            
            // Store the current character
            chars[ansIndex++] = chars[i];
            
            // Calculate the count of the current character
            int count = j - i;
            
            // If count is more than 1, store the count as well
            if (count > 1) {
                string cnt = to_string(count);
                for (char ch : cnt) {
                    chars[ansIndex++] = ch;
                }
            }
            
            // Move to the next unique character
            i = j;
        }
        
        // Return the length of the compressed array
        return ansIndex;
    }
};