class Solution {
    public int missingNumber(int[] nums) {
        return method1(nums);
    }

    private int method1(int[] nums) {
        /**
         * 0 1 2 4
         * 0 ^ 0 = 0
         * 0 ^ 1 ^ 1 = 0
         * 0 ^ 2 ^ 2 = 0
         * 0 ^ 3 ^ 4 = 3
         */
        int res = nums.length; 
        for (int i = 0; i < nums.length; ++i) {
            res ^= i ^ nums[i];
        }
        return res;
    }

    private int method2(int[] nums) {
        // 公式
        int expectedSum = nums.length * (nums.length + 1) / 2;
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        return expectedSum - actualSum;
    }
}
