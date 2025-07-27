class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int sum = 1; // First child always gets 1 candy
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                // Increasing slope
                up++;
                peak = up;
                down = 0;
                sum += up + 1;  // +1 for the current child
            }
            else if (ratings[i] < ratings[i - 1]) {
                // Decreasing slope
                up = 0;
                down++;
                sum += down;

                if (down > peak) {
                    // Add one extra to compensate peak child if needed
                    sum += 1;
                }
            }
            else {
                // Equal ratings
                up = down = peak = 0;
                sum += 1;
            }
        }

        return sum;
    }
};
