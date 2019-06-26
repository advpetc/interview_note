class Solution {
public:
    string reverseWords(string s)
    {
        /* return method1(s); */
        return method2(s);
    }

    string method1(string s)
    {
        int storeIndex = 0, n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                if (storeIndex != 0)
                    s[storeIndex++] = ' ';
                int j = i;
                while (j < n && s[j] != ' ') {
                    s[storeIndex++] = s[j++];
                }
                reverse(
                    s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.resize(storeIndex);
        return s;
    }

    string method2(string s)
    {
        istringstream is(s);
        s = "";
        string t = "";
        // istringstream, checker if is empty string, delimater
        while (getline(is, t, ' ')) {
            /* std::cout << "t is " << t << std::endl; */
            if (t.empty())
                continue;
            s = (s.empty() ? t : (t + " " + s));
        }
        return s;
    }
};
