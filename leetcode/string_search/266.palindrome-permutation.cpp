class Solution {
public:
    bool canPermutePalindrome(string s)
    {
        vector<bool> m(128, true);
        for (auto c : s) {
            if (m[c])
                m[c] = false;
            else
                m[c] = true;
        }
        int cnt = 0;
        for (auto e : m) {
            if (!e)
                cnt++;
        }
        return cnt == 0 && s.size() % 2 == 0 || cnt == 1 && s.size() % 2 == 1;
    }
};
