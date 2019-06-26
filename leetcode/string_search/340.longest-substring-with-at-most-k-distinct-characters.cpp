class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        vector<int> m(128, 0);
        int start = 0, end = 0, counter = 0, d = 0;
        while (end < s.size()) {
            if (m[s[end++]]++ == 0)
                counter++;
            while (counter > k) {
                if (m[s[start++]]-- == 1)
                    counter--;
            }
            d = max(d, end - start);
        }
        return d;
    }
};
