class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int l = 1, r = nums.size();
            while (l <= r) {
                int m = (l + r) / 2;
                int counter = 0;
                for (int n : nums) 
                    if (n <= m) counter++;
                counter > m ? r = m - 1 : l = m + 1;
            }
            return l;
        }
};
