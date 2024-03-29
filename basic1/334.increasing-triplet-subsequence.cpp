class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            int min = INT_MAX, secondMin = INT_MAX;           
            for (int num : nums)
            {
                if (num <= min) 
                    min = num;
                else if (num < secondMin)
                    secondMin = num;
                else if (num > secondMin)
                    return true;
            }
            return false;
        }
};
