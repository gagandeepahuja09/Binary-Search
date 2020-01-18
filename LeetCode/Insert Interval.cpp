class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0], right = newInterval[1];
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval);
        // prev has no intersection
        if(it != intervals.begin() && (*(--it))[1] < left)
            it++;
        // cout << (*it)[0];
        while(it != intervals.end() && (*it)[0] <= right) {
            left = min(left, (*it)[0]);
            // cout << (*it)[0];
            right = max(right, (*it)[1]);
            it = intervals.erase(it);
        }
        intervals.insert(it, { left, right });
        return intervals;
    }
};
