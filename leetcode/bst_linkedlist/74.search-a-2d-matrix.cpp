class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        return method2(matrix, target);
    }

    /*! \brief BST
     *
     *  Search by row first, then search by column
     *
     * \param matrix input matrix
     * \param target target to be found from matrix
     * \return exist or not
     */
    bool method1(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        if (target < matrix[0][0] || target > matrix.back().back())
            return false;
        int left = 0, right = matrix.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        int temp = right;
        left = 0;
        right = matrix[temp].size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[temp][mid] == target)
                return true;
            else if (matrix[temp][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    /*! \brief S sequence BST
     *
     *  regard as a 1D array
     *
     * \param matrix input matrix
     * \param target value to be found
     * \return exist or not
     */
    bool method2(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        if (target < matrix[0][0] || target > matrix.back().back())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
