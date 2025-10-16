// The API is already defined for you.
// int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2; // to prevent overflow

            int res = guess(mid); // API call

            if (res == 0)
                return mid;          // found the number
            else if (res == -1)
                high = mid - 1;      // number is smaller
            else
                low = mid + 1;       // number is larger
        }
        return -1; // just in case (though not needed)
    }
};
