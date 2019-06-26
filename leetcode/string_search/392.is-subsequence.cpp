class Solution {
public:
    bool isSubsequence(string& s, string& t)
    {
        /* return two_pointer(s, t); */
        return map_optimization(s, t);
    }

    bool two_pointer(string& s, string& t)
    {
        int i = 0;
        for (int j = 0; j < t.size() && i < s.size(); ++j) {
            if (s[i] == t[j])
                ++i;
        }
        return i == s.size();
    }

    bool map_optimization(string& s, string& t)
    {
        int pre = -1, n = t.size();
        unordered_map<char, vector<int>> char2pos;
        for (int i = 0; i < n; ++i)
            char2pos[t[i]].push_back(i);
        for (char c : s) {
            auto it = upper_bound(char2pos[c].begin(), char2pos[c].end(), pre);
            if (it == char2pos[c].end())
                return false;
            pre = *it;
        }
        return true;
    }
};
