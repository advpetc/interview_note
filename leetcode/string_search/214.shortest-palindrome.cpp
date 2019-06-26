class Solution {
public:
    string shortestPalindrome(string s)
    {
        return method1(s);
        /* return kmp(s); */
    }

    string method1(string s)
    {
        int i = 0, n = s.size();
        for (int j = n - 1; j >= 0; --j)
            if (s[i] == s[j])
                ++i;
        // current node is palindrome
        if (i == n)
            return s;
        string rem = s.substr(i);
        reverse(rem.begin(), rem.end());
        // the longest palindrome str is in 0 - i, but we cannot make sure 0 - i
        // is palindrome
        return rem + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }

    string kmp(string s)
    {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> next(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) {
            int j = next[i - 1];
            while (j > 0 && t[i] != t[j])
                j = next[j - 1];
            next[i] = (j += t[i] == t[j]);
        }
        return r.substr(0, s.size() - next.back()) + s;
    }
};
