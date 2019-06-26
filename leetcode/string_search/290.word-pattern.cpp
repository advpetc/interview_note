class Solution {
public:
    bool wordPattern(string pattern, string str)
    {
        /* return one_map(pattern, str); */
        return two_map(pattern, str);
    }
    bool one_map(string pattern, string str)
    {
        unordered_map<char, string> m;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (m.count(pattern[i])) {
                if (m[pattern[i]] != word)
                    return false;
            } else {
                // check if it's already been referenced
                for (auto a : m) {
                    if (a.second == word)
                        return false;
                }
                m[pattern[i]] = word;
            }
        }
        return i == n;
    }

    bool two_map(string pattern, string str)
    {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || m1[pattern[i]] != m2[word])
                return false;
            // by default the value is 0, so we need to + 1 for each index
            m1[pattern[i]] = m2[word] = i + 1;
        }
        return i == n;
    }
};
