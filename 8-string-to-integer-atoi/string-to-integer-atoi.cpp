class Solution {
public:
    int myAtoi(string s) {
        int i = 0, ans = 0;
        int n = s.size();

        // Skip spaces
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;

        // Sign
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check BEFORE update
            if (ans > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};
