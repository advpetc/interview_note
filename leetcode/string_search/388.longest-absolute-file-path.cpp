class Solution {
public:
    int lengthLongestPath(string input)
    {
        /* method 1 */
        /* int res = 0, n = input.size(), level = 0; */
        /* unordered_map<int, int> m{ { 0, 0 } }; */
        /* for (int i = 0; i < n; ++i) { */
        /*     int start = i; */
        /*     while (i < n && input[i] != '\n' && input[i] != '\t') { */
        /*         ++i; */
        /*     } */
        /*     if (i >= n || input[i] == '\n') { */
        /*         string t = input.substr(start, i - start); */
        /*         if (t.find('.') != string::npos) { */
        /*             res = max(res, m[level] + (int)t.size()); */
        /*         } else { */
        /*             ++level; */
        /*             m[level] = m[level - 1] + (int)t.size() + 1; */
        /*         } */
        /*         level = 0; */
        /*     } else { */
        /*         ++level; */
        /*     } */
        /* } */
        /* return res; */

        /* method 2 */
        int res = 0;
        istringstream ss(input);
        unordered_map<int, int> m{ { 0, 0 } };
        string line = "";
        while (getline(ss, line)) {
            int level = line.find_last_of('\t') + 1;
            int len = line.substr(level).size();
            if (line.find('.') != string::npos)
                res = max(res, m[level] + len);
            else
                m[level + 1] = m[level] + len + 1;
        }
        return res;
    }
};
