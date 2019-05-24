class Solution {
    /**
     * 
     only happen when 2 * 5 = 10
     O(logn) + space O(n)
     */
    public int trailingZeroes(int n) {
        // = 0 if is divisable by 5: use num of 5 to determine
        // how many zeros have appeared
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
}
