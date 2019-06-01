/* two pointer */
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int ret = 0;
            int l = 0, r = height.size() - 1;

            while (l < r) {
                ret = max(ret, (r - l) * min(height[l], height[r]));
                if (height[l] < height[r]) {
                    l++; 
                } else {
                    r--;
                }
            }
            return ret;
        }
};
