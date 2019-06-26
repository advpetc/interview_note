class Solution {
public:
    bool isMatch(string s, string p) { return two_pointer(s, p); }

    bool two_pointer(string s, string p)
    {
        int i = 0, j = 0, iStar = -1, jStar = -1;
        while (i < s.size()) {
            if (s[i] == p[j] || p[j] == '?') {
                ++i;
                ++j;
            } else if (p[j] == '*') {
                iStar = i;
                jStar = j++;
            } else if (iStar >= 0) {
                i = ++iStar;
                j = jStar + 1;
            } else {
                return false;
            }
        }
        while (j < p.size() && p[j] == '*') {
            ++j;
        }
        return j == p.size();
    }
};
