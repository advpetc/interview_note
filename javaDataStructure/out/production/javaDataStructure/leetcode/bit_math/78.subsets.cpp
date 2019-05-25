class Solution {
    public:
        vector<vector<int>> ret;

        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> temp;
            dfs(temp, nums, 0);
            return ret;
        }

        void dfs(vector<int> temp, vector<int>& nums, int index) {
            ret.push_back(temp);
            for (int i = index; i < nums.size(); ++i) {
                temp.push_back(nums[i]);
                dfs(temp, nums, i + 1);
                temp.pop_back();
            }
        }
};
