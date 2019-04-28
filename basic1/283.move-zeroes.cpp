class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0) return;
        int j = 0; // recording all the non-zero indexes
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0) 
            {
                int temp = nums[i];
                nums[i] = nums[j]; // swap the index with 0
                nums[j++] = temp; // if not zero, then move it the the non-zero index place
            }
        }
    }
};
