class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        /* return brute_force(strs); */
        return sort_method(strs);
    }

    /*! \brief brute force
     *
     *  using the first str to keep checking util to the end
     *
     * \param strs inputs strings
     * \return common prefix
     */
    string brute_force(vector<string>& strs)
    {
        if (strs.empty())
            return "";
        string res = "";
        for (int j = 0; j < strs[0].size(); ++j) {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); ++i) {
                if (j >= strs[i].size() || strs[i][j] != c)
                    return res;
            }
            res.push_back(c);
        }
        return res;
    }

    /*! \brief sort
     *
     *  sort vector based on character
     *
     * \param strs inputs strings
     * \return common prefix
     */
    string sort_method(vector<string>& strs)
    {
        if (strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        int i = 0, len = min(strs[0].size(), strs.back().size());
        while (i < len && strs[0][i] == strs.back()[i]) {
            ++i;
        }
        return strs[0].substr(0, i);
    }
};
