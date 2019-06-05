class Solution {
    public:
        int maximumGap(vector<int>& nums) {
            if (nums.size() < 2) {
                return 0; 
            }

            int m = nums[0]; // global maximum
            for (int i = 1; i < nums.size(); ++i) {
                m = max(m, nums[i]);
            }

            int exp = 1; // 1, 10, 100, 100
            int R = 10;  // 10 digits
            vector<int> aux(nums.size());
            while (m / exp > 0) { // Go through all digits from LSB to MSB
                vector<int> count(R);
                for (int i = 0; i < nums.size(); ++i) {
                    count[(nums[i] / exp) % 10]++;
                }

                for (int i = 1; i < count.size(); ++i) {
                    count[i] += count[i - 1];
                }

                for (int i = nums.size() - 1; i >= 0; ++i) {
                    aux[--count[(nums[i] / exp) % 10]] = nums[i];
                }

                for (int i = 0; i < nums.size(); ++i) {
                    nums[i] = aux[i];
                }
                exp *= 10; // next digit
            }

            int max_gap = 0;
            for (int i = 1; i < aux.size(); ++i) {
                max_gap = max(max_gap, aux[i] - aux[i - 1]);
            }

            return max_gap;
        }
};
