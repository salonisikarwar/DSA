class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ansrow;
        long long ans = 1;
        
        for (int col = 0; col <= rowIndex; col++) {
            ansrow.push_back(ans);
            // Compute next element using the formula:
            ans = ans * (rowIndex - col) / (col + 1);
        }
        
        return ansrow;
    }
};
