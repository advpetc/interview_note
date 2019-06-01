class WordDistance {
    private:
        unordered_map<string, vector<int>> cache;
    public:
        WordDistance(vector<string>& words) {
            for (int i = 0; i < words.size(); ++i) {
                cache[words[i]].push_back(i);
            }
        }

        /* O(m + n) */
        int shortest(string word1, string word2) {
            int ret = INT_MAX, i = 0, j = 0;
            while (i < cache[word1].size() && j < cache[word2].size()) {
                ret = min(ret, abs(cache[word1][i] - cache[word2][j]));
                cache[word1][i] < cache[word2][j] ? i++ : j++;
            }
            return ret;
        }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
