class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        
        for(int i = 0; i < n; i++) {
            // While we can remove more digits and the top of stack is greater than current digit
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        // If k > 0, remove from the end
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Build the result from the stack (will be reversed order)
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        // Reverse the string since stack gives digits in reverse
        reverse(res.begin(), res.end());
        
        // Remove leading zeros
        while(res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }
        
        // If empty after removing zeros, return "0"
        if(res.empty()) return "0";
        
        return res;
    }
};
