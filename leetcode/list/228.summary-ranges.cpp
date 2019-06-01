class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            if (nums.size() == 0) {
                return {}; 
            }
            vector<string> ret;
            for (int i = 0, j = 0; i < nums.size(); ++i) {
                if (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
                    continue; 
                } 

                if (i == j) {
                    ret.push_back(to_string(nums[j]));
                } else {
                    ret.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
                }
                j = i + 1;
            }
            return ret;
        }
};
