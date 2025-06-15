class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        //Maximize 
        string maxStr = s;
        for(char c :s)
        if(c != '9')
        {
            char toReplace = c;
            for(char& ch: maxStr)
            {
                if(ch == toReplace)
                ch ='9';
            }
            break;
        }
        //MINIMIZE

                string minStr = s;
                if(s[0] != '1')
                {
                    char toReplace = s[0];
                    for(char &ch :minStr)
                    { 
                        if(ch ==toReplace) ch = '1';
                    }
                }
                else{
                    for(int i =1;i<s.length(); ++i)
                    {
                        if(s[i]!='0' && s[i] !='1')
                        {
                            char toReplace = s[i];
                            for(char &ch :minStr)
                            {
                                if(ch ==toReplace) ch ='0';
                            }
                            break;
                        }

                    }
                }

        int maxNum = stoi(maxStr);
int minNum = stoi (minStr);
    
return maxNum-minNum;
        
    }
};