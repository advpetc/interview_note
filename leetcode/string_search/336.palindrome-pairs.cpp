class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        vector<vector<int>> res;
        unordered_map<string, int> m;
        set<int> s;
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        for (int i = 0; i < words.size(); ++i) {
            string t = words[i];
            int len = t.size();
            reverse(t.begin(), t.end());
            if (m.count(t) && m[t] != i)
                res.push_back({ i, m[t] });
            auto a = s.find(len);
            for (auto it : a) {
                int d = *it;
                if (isValid(t, 0, len - d, 1) && m.count(t.substr(len - d)))
                    res.push_back({ i, m[t.substr(len - d)] });
                if (isValid(t, d, len - 1) && m.count(t.substr(0, d)))
                    res.push_back({ m[t.substr(0, d)], i });
            }
        }
        return res;
    }
};
