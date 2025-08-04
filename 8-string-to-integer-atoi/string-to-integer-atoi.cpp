class Solution {
public:
    int myAtoi(string s) {

        if (s.length() == 0) return 0;

        int i = 0;

        
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // now substring from first non-space character
        s = s.substr(i); // Reset s to trimmed string

        int sign = +1;
        long ans = 0;

        
        if (s[0] == '-') sign = -1;

        // Declare MAX and MIN
        int MAX = INT_MAX, MIN = INT_MIN;

        //  Move i to start of digits, only if + or - exists
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        // 
        while (i < s.length()) {

            //  check s[i] not s[0]
            if (!isdigit(s[i])) break;

            // convert char to digit and build answer
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow
            if (sign == -1 && -1 * ans < MIN) return MIN;
            if (sign == 1 && ans > MAX) return MAX;

            i++;
        }

        return (int)(sign * ans);
    }
};
