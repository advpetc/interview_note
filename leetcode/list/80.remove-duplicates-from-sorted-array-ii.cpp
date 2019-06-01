class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i = 0, j = 0;
            for (; j < nums.size(); ++j) {
                if (i < 2 || nums[i - 2] != nums[j]) {
                    nums[i++] = nums[j];
                }
            }
            return i;
        }
};
