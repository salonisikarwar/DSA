class Solution {
public:
    string intToRoman(int num) {
        string result = "";

        for (int i = 0; i < val.size(); i++) {
            int times = num / val[i];

            while (times--) {
                result += sym[i];
            }

            num %= val[i];
        }

        return result;
    }

private:
    // Declare constant lookup tables as static class members
    static const vector<int> val;
    static const vector<string> sym;
};

// Define the static members outside the class
const vector<int> Solution::val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const vector<string> Solution::sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
