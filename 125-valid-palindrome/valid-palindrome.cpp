class Solution {
public:
bool isvalid(char ch)
{
    if(ch>='a'&& ch<='z'||ch>='A'&& ch<='Z'||ch>='0'&&ch<='9'){
    return 1;}
    else return 0;

}
char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

bool palindrome(string s)
{
    int st = 0;
    int end = s.length()-1;
    while(st<=end)
    {
        if(s[st] !=s[end]) return 0;
        st++;
        end--;
    }
    return 1;

}

    bool isPalindrome(string s) {

        string temp = "" ;
        int n  = s.length();
        for(int i  =0;i<n ;i++)
        {
            if(isvalid(s[i]))
            {
                temp.push_back(s[i]);
            }
        }
        for(int i  = 0 ;i<temp.length() ;i++)
        {
  temp[i] = tolower(temp[i]);        }
  return palindrome(temp);

    }
};