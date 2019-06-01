class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            /* method1(nums1, m, nums2, n); */
            method2(nums1, m, nums2, n);
        }

        /******************************************************************************
        * Function:         void method1
        * Description:      using a third list to store num1, make comparison each
        *                   iteration to determine which one to insert
        *                   time: O(n + m), space: O(m)
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        void method1(vector<int>& nums1, int m, vector<int>& nums2, int n){
            
            vector<int> nums1_copy(nums1);
            // get pointer
            int p1 = 0, p2 = 0;

            // set pointer
            int p = 0;
            while ((p1 < m) && (p2 < n)) {
                nums1[p++] = (nums1_copy[p1] < nums2[p2]) ? nums1_copy[p1++] : nums2[p2++];
            }

            if (p1 < m) {
                for (; p1 < m; ++p, ++p1) {
                    nums1[p] = nums1_copy[p1];
                }
            }

            if (p2 < n) {
                for (; p2 < n; ++p, ++p2) {
                    nums1[p] = nums2[p2];
                }
            }
        }

        /******************************************************************************
        * Function:         void method2
        * Description:      override nums1 from the end
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        void method2(vector<int>& nums1, int m, vector<int>& nums2, int n){
            int p1 = m - 1, p2 = n - 1;
            // last elem of nums1
            int p = m + n - 1;
            while ((p1 >= 0) && (p2 >= 0)) {
                nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
            }
            while (p2 >= 0) {
                nums1[p--] = nums2[p2--];
            }
        }
};
