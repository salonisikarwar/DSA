class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0; // count of vowels in current window
        int maxCnt = 0;
        
        // Count vowels in the first window
        for(int i = 0; i < k; i++)
            if(isVowel(s[i])) cnt++;
        
        maxCnt = cnt;
        
        // Slide the window
        for(int i = k; i < n; i++) {
            if(isVowel(s[i])) cnt++;        
            if(isVowel(s[i - k])) cnt--;      // remove character leaving the window
            maxCnt = max(maxCnt, cnt);        // update max
        }
        
        return maxCnt;
    }
};
