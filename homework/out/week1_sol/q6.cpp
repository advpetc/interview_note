/*
 * q6.cpp
 * Copyright (C) 2019 Haoyang <peter@peterchen.xyz>
 *
 * Distributed under terms of the MIT license.
 */
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.size () == 0) return 0;
    // auto compare = [](const Interval& a, const Interval& b) {return a.start < b.start;};
    // sort (intervals.begin (), intervals.end (), compare);
    priority_queue <int, vector<int>, std::greater<int>> pq;
    pq.push (intervals[0][1]);
    vector<pair<int, int>> freeTime;
    for (unsigned i = 1; i < intervals.size(); ++i)
    {
        // start is later than last ended interval
        if (intervals[i][0] >= pq.top ()) {
            int start = pq.top();
            int end = intervals[i][0];
            freeTime.push_back(make_pair(start, end));
            pq.pop ();  
        } 
        pq.push (intervals[i][1]);
    }
    for (auto p : freeTime)
        cout << "start: " << p.first << " end: " << p.second << endl;
    return pq.size ();
}

int main(int argc, char *argv[]) {
    vector<vector<int>> test1{{0,30},{5,10},{15,20}, {40, 50}}; 
    cout << minMeetingRooms(test1) << endl;
}
