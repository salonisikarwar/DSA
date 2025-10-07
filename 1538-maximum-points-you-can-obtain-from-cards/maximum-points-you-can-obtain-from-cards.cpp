class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, maxsum = 0;
        int n = cardPoints.size();

        // Take first k cards from the left
        for(int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        maxsum = lsum;
	int rindex = n-1;
       for (int i = k - 1; i >= 0; i--) {
    lsum -= cardPoints[i];
    rsum += cardPoints[rindex];
    maxsum = max(maxsum, lsum + rsum);
    rindex = rindex - 1;
}

        return maxsum;
    }
};
