class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        /* return method1(heights); */
        return method2(heights);
    }
    int method1(vector<int>& heights)
    {
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (i + 1 < heights.size() && heights[i] <= heights[i + 1]) {
                continue;
            }
            int minH = heights[i];
            for (int j = i; j >= 0; --j) {
                minH = min(minH, heights[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
    }

    /*! \brief stack
     *
     *  using stack to find local max
     *
     * \param heights inputs histogram
     * \return max area
     */
    int method2(vector<int>& heights)
    {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            if (st.empty() || heights[st.top()] < heights[i]) {
                st.push(i);
            } else {
                int cur = st.top();
                st.pop();
                res = max(
                    res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }
        }
        return;
    }
};
