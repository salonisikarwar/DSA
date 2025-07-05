class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        const int mod = 1e9 + 7; // Optional: Only needed if modulus is required

        vector<int> prev(m, 0);

        for(int i = 0; i < n; i++) {
            vector<int> curr(m, 0);

            for(int j = 0; j < m; j++) {
                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                }
                else if(i == 0 && j == 0) {
                    curr[j] = 1;
                }
                else {
                    int up = 0, left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];
                    curr[j] = up + left; // or use: (up + left) % mod;
                }
            }

            prev = curr;
        }

        return prev[m-1];
    }
};

