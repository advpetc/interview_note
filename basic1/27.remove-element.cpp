class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != val) 
                nums[res++] = nums[i]; // only update res if nums doesn't include value
        return res;
    }
    
};
