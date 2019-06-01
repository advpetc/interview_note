class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size());
            int len = 0;
            for (int num : nums) {
                int l = 0, r = len;
                while (l != r) {
                    int mid = (r + l) / 2;
                    if (dp[mid] < num) {
                        l = mid + 1; 
                    } else {
                        r = mid; 
                    }
                }
                dp[l] = num;
                if (l == len) {
                    len++; 
                }
            }
            return len;
        }
};
