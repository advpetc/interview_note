class Solution {
public:
    string decodeString(string s) { return stack_method(s); }

    /*! \brief stack
     *
     *  using stack to store all element within [] and then number
     *
     * \param s string
     * \return string
     */
    string stack_method(string s)
    {
        string t = "";
        stack<int> s_num;
        stack<string> s_str;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = 10 * cnt + s[i] - '0';
            } else if (s[i] == '[') {
                s_num.push(cnt);
                s_str.push(t);
                cnt = 0;
                t.clear();
            } else if (s[i] == ']') {
                int k = s_num.top();
                s_num.pop();
                for (int j = 0; j < k; ++j) {
                    s_str.top() += t;
                }
                t = s_str.top();
                s_str.pop();
            } else {
                t += s[i];
            }
        }
        return s_str.empty() ? t : s_str.top();
    }
};