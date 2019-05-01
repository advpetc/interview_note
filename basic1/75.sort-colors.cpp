class Solution {
    public:
        void sortColors(vector<int>& nums) {
            if (nums.size() == 0) return;
            int start = 0, end = nums.size() - 1;
            int index = 0;
            while (index <= end)
            {
                if (nums[index] == 0) 
                    swap(nums[index++], nums[start++]);
                else if (nums[index] == 1)
                    index++;
                else
                    swap(nums[index], nums[end--]);
            }
        }
};
