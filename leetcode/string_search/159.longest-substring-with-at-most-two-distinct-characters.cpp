class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s)
    {
        vector<int> v(128, 0);
        int start = 0, end = 0, d = 0, counter = 0;
        while (end < s.size()) {
            if (v[s[end++]]++ == 0)
                counter++;
            while (counter > 2) {
                if (v[s[start++]]-- == 1)
                    counter--;
            }
            d = max(d, end - start);
        }
        return d;
    }
};
