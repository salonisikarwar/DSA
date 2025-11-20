class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> visited;

    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        help(nums);
        return ans;
    }

    void help(vector<int>& nums) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            visited[i] = true;
            curr.push_back(nums[i]);

            help(nums);

            curr.pop_back();
            visited[i] = false;
        }
    }
};
