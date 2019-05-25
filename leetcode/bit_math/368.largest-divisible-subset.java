class Solution {
    /**
     * pre: previous element's index that is divisible to current element
     * so that we only need the last element to track the entire sequence
     * 
     */
    public List<Integer> largestDivisibleSubset(int[] nums) {
        if (nums == null || nums.length == 0) {
            return new ArrayList<>();
        }
        Arrays.sort(nums);
        int[] count = new int[nums.length];
        int[] pre = new int[nums.length];
        int max = 0, index = -1;
        for (int i = 0; i < nums.length; i++) {
            count[i] = 1;
            pre[i] = -1;      
            for (int j = i - 1; j >= 0; j--) {
                // check if pre is divisible
                if (nums[i] % nums[j] == 0) {
                    if (1 + count[j] > count[i]) {
                        count[i] = count[j] + 1;
                        pre[i] = j;
                    }
                } 
                if (count[i] > max) {
                    max = count[i];
                    index = i;
                }
            }
        } 
        List<Integer> res = new ArrayList<>();
        while (index != -1) {
            res.add(nums[index]);
            index = pre[index];
        }
        return nums.length == 1 ? Arrays.asList(nums[0]) : res;
    }
}
