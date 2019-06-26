class Solution {
public:
    bool isOneEditDistance(string s, string t)
    {
        if (s.size() < t.size())
            swap(s, t);
        int m = s.size(), n = t.size(), diff = m - n;
        if (diff >= 2)
            return false;
        else if (diff == 1) {
            for (int i = 0; i < n; ++i) {
                // if current char are different, then check the rest
                if (s[i] != t[i]) {
                    return s.substr(i + 1) == t.substr(i);
                }
            }
            // just add one more char
            return true;
        } else {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if (s[i] != t[i])
                    ++cnt;
            }
            // can only have one differ
            return cnt == 1;
        }
    }
};
