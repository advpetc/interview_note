class Solution {
    public:
        int minSubArrayLen(int s, vector<int>& nums) {
            if (nums.size() == 0) return 0;
            int size = nums.size();
            int l = 0; // starting point [index]
            int sum = 0;
            int ret = INT_MAX;
            for (int i = 0; i < size; ++i) {
                sum += nums[i];
                while (sum >= s) {
                    ret = min(ret, i - l + 1);
                    sum -= nums[l++];
                }
            }
            return ret == INT_MAX ? 0 : ret;
        }
};
