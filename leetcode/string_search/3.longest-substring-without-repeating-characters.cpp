class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        /* return method1(s); */
        return recommend(s);
    }

    int method1(string s)
    {
        vector<int> m(128, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }

    // check out 340
    int recommend(string s)
    {
        vector<int> v(128, 0);
        int start = 0, end = 0, d = 0, counter = 0;
        while (end < s.size()) {
            if (v[s[end++]]++ > 0)
                counter++;
            while (counter > 0) {
                if (v[s[start++]]-- > 1)
                    counter--;
            }
            d = max(d, end - start);
        }
        return d;
    }
};
