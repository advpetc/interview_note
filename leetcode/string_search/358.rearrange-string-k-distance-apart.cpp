class Solution {
public:
    string rearrangeString(string str, int k)
    {
        if (k == 0)
            return str;
        string res;
        int len = (int)str.size();
        unordered_map<char, int> m; // each character in str -> # of occurance
        priority_queue<pair<int, char>>
            q; // max heap by comparing key of pair -> first
        for (auto a : str) {
            ++m[a];
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            q.push({ it->second, it->first });
        }
        while (!q.empty()) {
            vector<pair<int, int>> v;
            int cnt = min(k, len);
            for (int i = 0; i < cnt; ++i) {
                if (q.empty())
                    return "";
                auto t = q.top();
                q.pop();
                res.push_back(t.second);
                if (--t.first > 0)
                    v.push_back(t);
                --len;
            }
            for (auto a : v) {
                q.push(a);
            }
        }
        return res;
    }
};
