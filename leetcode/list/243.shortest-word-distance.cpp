class Solution {
    public:
        int shortestDistance(vector<string>& words, string word1, string word2) {
            int w1 = -1, w2 = -1;
            int ret = words.size();
            for (int i = 0; i < words.size(); ++i) {
                if (words[i] == word1) {
                    w1 = i; 
                } 

                if (words[i] == word2) {
                    w2 = i; 
                }

                if (w1 != -1 && w2 != -1) {
                    ret = min(ret, abs(w1 - w2));
                }
            }
            return ret;
        }
};
