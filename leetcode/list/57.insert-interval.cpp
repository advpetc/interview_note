class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> left, right;
            int s = newInterval[0], e = newInterval[1];
            for (auto& i : intervals) {
                if (i[1] < s) { // all less than newInterval
                    left.push_back(i);
                } else if (i[0] > e) { // all greater than newInterval
                    right.push_back(i);
                } else {
                    s = min(s, i[0]); // the one needs to be merged
                    e = max(e, i[1]);
                }
            }
            left.push_back({s, e});
            // O(n)
            left.insert(left.end(), right.begin(), right.end());
            return left;
        }
};
