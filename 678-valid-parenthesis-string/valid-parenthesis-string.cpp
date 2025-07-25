class Solution {
public:
bool checkValidString(string s) {
    int minOpen = 0, maxOpen = 0;
    
    for (char c : s) {
        if (c == '(') {
            minOpen++;
            maxOpen++;
        } else if (c == ')') {
            minOpen--;
            maxOpen--;
        } else { // c == '*'
            minOpen--;  // * as )
            maxOpen++;  // * as (
        }

        if (maxOpen < 0) return false; // Too many ')'

        if (minOpen < 0) minOpen = 0; // * can act as empty string to fix negatives
    }

    return minOpen == 0;
}

};