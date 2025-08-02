class Solution {
public:

    string reverseWords(string s) {
        // reverse whole string
        reverse(s.begin() , s.end());
        int  i =0;
        // l and r reverse karenge words ko

        int l = 0  , r=0 ;
        int n = s.length();
        while(i <n)
        {
            while(i<n && s[i] != ' ')
            {
                //i kp agar char dikha to r ko dega and i++ and r++
                s[r] = s[i];
                i++;
                r++;
            }
            if( l<r)
            {
                reverse(s.begin()+l , s.begin()+r);
                s[r]  = ' ';
                r++;
                l = r;

            }

            i ++;
            //ye toh bhdta rhegga
        }
            s = s.substr(0 , r-1);
        return s;
    }
};