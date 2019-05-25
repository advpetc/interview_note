class Solution {
    /**
     * 2: 10
     * 4: 100
     * 8: 1000
     * 16: 10000
     * if n is power of two:
     * n - 1 = 0111111
     */
    public boolean isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        else
            return ((n & (n - 1)) == 0);
    }
}
