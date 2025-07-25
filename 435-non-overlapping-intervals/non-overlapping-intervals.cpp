class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];  // sort by end time
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), comp);

        int cnt = 1; // count of non-overlapping intervals
        int lastEndTime = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastEndTime) {
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }

        return intervals.size() - cnt;
    }
};
