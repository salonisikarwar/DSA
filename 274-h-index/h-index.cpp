class Solution {
public:
    int hIndex(vector<int>& citations) {
        int papers = citations.size();

        // buckets[i] = number of papers with exactly i citations
        vector<int> citationBuckets(papers + 1, 0);

        // Fill buckets
        for (int citation : citations) {
            if (citation >= papers) {
                citationBuckets[papers]++;
            } else {
                citationBuckets[citation]++;
            }
        }

        int cnt = 0;

        // Traverse from high to low
        for (int i = papers; i >= 0; i--) {
            cnt += citationBuckets[i];
            if (cnt >= i) {
                return i;
            }
        }

        return 0;
    }
};
