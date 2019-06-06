class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        return method3(matrix, k);
    }

    /*! \brief Heap
     *
     *  keep K element on heap
     *
     * \param maxtrix input matrix
     * \param k top num
     * \return the kth value
     */
    int method1(vector<vector<int>>& matrix, int k)
    {
        priority_queue<int> q;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                q.emplace(matrix[i][j]);
                if (q.size() > k)
                    q.pop();
            }
        }
        return q.top();
    }

    /******************************************************************************
     * Function:         int method2
     * Description:
     * Where:
     * Return:
     * Error:
     *****************************************************************************/
    int method2(vector<vector<int>>& matrix, int k)
    {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = (left + right) / 2, cnt = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid)
                    - matrix[i].begin();
            }
            if (cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    /******************************************************************************
     * Function:
     * Description: compare cnt with k, find the correct k
     * Where:
     * Return:
     * Error:
     *****************************************************************************/
    int method3(vector<vector<int>>& matrix, int k)
    {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = search_less_equal(matrix, mid);
            if (cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    int search_less_equal(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size(), i = n - 1, j = 0, res = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                res += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return res;
    }
};
