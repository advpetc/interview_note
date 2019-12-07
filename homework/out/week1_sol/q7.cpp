class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size () == 0) return 0;

        auto compare = [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];};
        auto compare2 = [](const vector<int>& a, const vector<int>& b) {return a[1] > b[1];};

        sort (intervals.begin (), intervals.end (), compare);
        using MyPQ = priority_queue<vector<int>, vector<vector<int>>, decltype(compare2)>;
        MyPQ pq(compare2);
        pq.push (intervals[0]);

        for (unsigned i = 1; i < intervals.size (); ++i)
        {
            if (intervals[i][0] >= pq.top()[1]) pq.pop();
            pq.push(intervals[i]);
        }

        int ret = pq.size();
        while (!pq.empty()) {
            cout << pq.top()[0] << " - " << pq.top()[1] << endl;
            pq.pop();
        }
        return ret;
    }
};
