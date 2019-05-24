class Solution {
    /**
     * upto 10, there is 1 one
     * 20, 2
     * 30, 4 (21, 11, 10, 1)
     * ...
     * 16x (x > 1), there are 17 ones
     * (n / 10) + (n % 10 != 0)
     */
    public int countDigitOne(int n) {
        int res = 0;
        for (long m = 1; m <= n; m *= 10) {
            long a = n / m;
            long b = n % m;
            res += (a + 8) / 10 * m;
            if (a % 10 == 1) res += b + 1;
        }
        return res; 
    }
}
