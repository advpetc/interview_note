class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            /* method1(nums, k); */
            method2(nums, k);
        }

        /******************************************************************************
        * Function:         void method1
        * Description:      Brute Force, shift all element by one one time.
        * Where:
        * Return:           
        * Error:            Time Limit Exeeded
        *****************************************************************************/
        void method1(vector<int>& nums, int k){
            int temp, previous;
            for (int i = 0; i < k; ++i) {
                previous = nums.back();
                for (int j = 0; j < nums.size(); ++j) {
                    swap(nums[j], previous);
                }
            }
        }

        /******************************************************************************
        * Function:         void method2
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        void method2(vector<int>& nums, int k){
            if (nums.empty() || (k %= nums.size()) == 0)
                return;
            int start = 0, idx = 0, pre = 0, curr = nums[0], n = nums.size();
            for (int i = 0; i < n; ++i) {
                pre = curr;
                idx = (idx + k) % n;
                curr = nums[idx];
                nums[idx] = pre;
                if (idx == start) {
                    idx = ++start;
                    curr = nums[idx];
                }
            }
        }
};
