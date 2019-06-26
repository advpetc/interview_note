class Solution {
public:
    int titleToNumber(string s)
    {
        int n = s.size(), res = 0;
        long tmp = 1;
        for (int i = n; i >= 1; --i) {
            res += (s[i - 1] - 'A' + 1) * tmp;
            tmp *= 26;
        }
        return (int)res;
    }
};
