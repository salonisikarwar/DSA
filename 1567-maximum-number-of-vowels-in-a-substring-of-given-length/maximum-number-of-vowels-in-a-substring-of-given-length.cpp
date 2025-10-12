class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            c = tolower(c);
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };

        int cnt = 0;      // current vowel count
        int maxCnt = 0;   // maximum vowels

        // First window
        for(int i = 0; i < k; i++)
            cnt += isVowel(s[i]);
        maxCnt = cnt;

        // Slide the window
        for(int i = k; i < s.size(); i++) {
            cnt += isVowel(s[i]) - isVowel(s[i - k]); // add new, remove old
            if(cnt == k) return k;                    // early exit: max possible
            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }
};
