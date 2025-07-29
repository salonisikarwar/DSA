class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
          int n = score.size();
        int maxScore = *max_element(score.begin(), score.end());
        
        // Bucket for counting sort
        vector<int> index(maxScore + 1, -1);
        
        for (int i = 0; i < n; ++i) {
            index[score[i]] = i;
        }

        vector<string> res(n);
        int rank = 1;

        for (int s = maxScore; s >= 0; --s) {
            if (index[s] != -1) {
                string r;
                if (rank == 1) r = "Gold Medal";
                else if (rank == 2) r = "Silver Medal";
                else if (rank == 3) r = "Bronze Medal";
                else r = to_string(rank);
                res[index[s]] = r;
                ++rank;
            }
        }

        return res;
        
    }
};