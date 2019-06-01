#define ch(c) (c - 'a')

class Solution {
    public:
        int firstUniqChar(string s) {
            vector<int> dict(26);
            for (char i : s) {
                dict[ch(i)]++;
            }
            for (int j = 0; j < s.size(); ++j) {
                if (dict[ch(s[j])] == 1) 
                    return j;
            }
            return -1;
        }
};
