class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                for (int k = j + 1; k < len; ++k) {
                    int offset = target - nums[i] - nums[j] - nums[k];
                    if (offset < nums[k])
                        break;
                    if (!binary_search(
                            nums.begin() + k + 1, nums.end(), offset))
                        continue;
                    vector<int> temp{ nums[i], nums[j], nums[k], offset };
                    s.insert(temp);
                }
            }
        }
        return vector<vector<int>>(s.begin(), s.end());
    }
};
