class Solution {
public:
 int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size();
        int m = text2.size();
        vector<int>prev(m+1, 0), curr(m+1,0);
        
       
        for(int i  = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(text1[i-1]== text2[j-1])  curr[j]= 1+prev[j-1 ];
                 else curr[j] =  0+ max(prev[j] , curr[j-1]);
            }
            prev = curr;
        }
       return prev[m]; 
          }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin() , t.end());
        return longestCommonSubsequence(s,t);
    }
    int minInsertions(string s) {
        return s.size()- longestPalindromeSubseq( s);
    }
};