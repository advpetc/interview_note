class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            if (k <= 0 || nums.size() < k) {
                return {}; 
            }

            auto comp = [](const pair<int, int>& left, const pair<int, int>& right) {
                return left.second < right.second;
            };

            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
            unordered_map<int, int> map;

            for (int i : nums) {
                map[i]++;
            }

            for (auto pair : map) {
                pq.push(pair);
            }
            vector<int> ret;

            while (ret.size() != k) {
                ret.push_back(pq.top().first);
                pq.pop();
            }
            return ret;
        }
};
