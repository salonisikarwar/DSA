class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;

    int prev2 = 1;  // f(0)
    int prev  = 1;  // f(1)

    for (int i = 2; i <= n; i++) {
        int curr = prev + prev2; // f(i) = f(i-1) + f(i-2)
        prev2 = prev;
        prev = curr;
    }

    return prev;
    }
};