class Solution {
    public:
        int trap(vector<int>& height) {
            if (height.size() <= 1) {
                return 0; 
            }

            vector<int> l_max(height.size());
            vector<int> r_max(height.size());
                
            l_max[0] = height[0];
            l_max.front() = height.front();
            for (int i = 1; i < height.size(); ++i) {
                l_max[i] = max(height[i], l_max[i - 1]);
            }

            /* r_max[height.size() - 1] = height[height.size() - 1]; */
            r_max.back() = height.back();
            for (int i = height.size() - 2; i >= 0; --i) {
                r_max[i] = max(height[i], r_max[i + 1]);
            }

            int retval = 0;
            for (int i = 0; i < height.size(); ++i) {
                retval += min(l_max[i], r_max[i]) - height[i];
            }

            return retval;
        }
};
