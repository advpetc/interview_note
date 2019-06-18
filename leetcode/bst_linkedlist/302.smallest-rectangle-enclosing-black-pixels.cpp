class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y)
    {
        /* TODO:  <04-06-19, Haoyang Chen> */
        /* return brute_force(image, x, y); */
        return bst(image, x, y);
    }

    /*! \brief Brute Force iterative
     *
     *  two for loops to iterate through all the points, if there is a black dot
     * ('1'), then start tracking the left, right, up and down coordinates
     *
     * \param image input picture
     * \param x starting x coordinate
     * \param y starting y coordinate
     * \return the area that can round up all the '1' area
     */
    int brute_force(vector<vector<char>>& image, int x, int y)
    {
        int left = y, right = y, up = x, down = x;
        for (int i = 0; i < image.size(); ++i) {
            for (int j = 0; j < image[i].size(); ++j) {
                if (image[i][j] == '1') {
                    left = min(left, j);
                    right = max(right, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        return (right - left + 1) * (down - up + 1);
    }

    /*! \brief Bst
     *
     *  using bst
     *
     * \param image input
     * \param x x coordinate
     * \param y y coordinate
     * \return mininal area
     */
    int bst(vector<vector<char>>& image, int x, int y)
    {
        int m = image.size(), n = image[0].size();
        int up = binary_search(image, true, 0, x, 0, n, true);
        int down = binary_search(image, true, x + 1, m, 0, n, false);
        int left = binary_search(image, false, 0, y, up, down, true);
        int right = binary_search(image, false, y + 1, n, up, down, false);
        return (right - left) * (down - up);
    }

    /******************************************************************************
     * Function:         int binary_search
     * Description:      using binary search
     * Where:
     * Return:
     * Error:
     *****************************************************************************/
    int binary_search(vector<vector<char>>& image, bool h, int i, int j,
        int low, int high, bool opt)
    {
        while (i < j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (h ? image[mid][k] : image[k][mid]) == '0') {
                ++k;
            }
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
};
