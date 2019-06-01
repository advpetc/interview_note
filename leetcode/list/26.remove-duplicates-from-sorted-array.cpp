class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() == 0) { return 0; }

            int i = 0, j = 1;
            for (; j < nums.size(); ++j) {
                if (nums[i] != nums[j]) {
                    nums[++i] = nums[j];
                }
            }
            
            return i + 1;
        }
};
