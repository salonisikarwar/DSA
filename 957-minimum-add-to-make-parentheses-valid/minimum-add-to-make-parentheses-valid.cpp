class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        for(int c = 0 ;c<s.size();c++)
        {
            if(s[c]== '('){open++;}
            else if(s[c]==')'&& open>0)
            {
                open--;
            }
            else{
                close++;
            }
        }
        return open +close;
    }
};