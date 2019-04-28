class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> m; // nums -> count
            for (int n : nums)
                m[n]++;
            vector<vector<int>> bucket(nums.size() + 1, vector<int>(0));
            for (int n : nums)
            {
                int freq = m[n];
                bucket[freq].push_back(n);
            }
            vector<int> res;
            for (int i = nums.size() - 1; i >= 0 && res.size() < k; --i)
                if (bucket[i].size() != 0)
                    res.insert(res.end(), bucket[i].begin(), bucket[i].end());
            return res;
        }
};
