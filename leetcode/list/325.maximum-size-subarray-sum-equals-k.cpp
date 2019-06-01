class Solution {
    public:
        int maxSubArrayLen(vector<int>& nums, int k) {
            // The HashMap stores the sum of all elements before index i as key,
            // and i as value
            unordered_map<int, int> sums;
            int cur_sum = 0, max_len = 0;
            for (int i = 0; i < nums.size(); ++i) {
                cur_sum += nums[i];
                // For each i, check not only the current sum but also
                // (currentSum - previousSum) to see if there is any that equals
                // k, and update max length.
                if (cur_sum == k) {
                    max_len = i + 1;
                } else if (sums.count(cur_sum - k)) {
                    max_len = max(max_len, i - sums[cur_sum - k]);
                }

                if (!sums.count(cur_sum)) {
                    sums[cur_sum] = i;
                }
            }
            return max_len;
        }
};
