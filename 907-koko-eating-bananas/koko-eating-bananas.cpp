class Solution {
public:
    long long fun(vector<int>& piles, int hourly) {
        int n = piles.size();
        long long totalhrs = 0;
        for (int i = 0; i < n; i++) {
            totalhrs += (piles[i] + hourly - 1) / hourly;  // Using integer division
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxPile;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = fun(piles, mid);  // Make sure it's long long

            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};