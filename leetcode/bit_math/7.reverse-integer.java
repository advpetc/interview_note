class Solution {
    public int reverse(int x) {
        /**
         * int: 2^32-1 -- -2^32-1
         * long 64 bits
         */
        long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
            if (res > Integer.MAX_VALUE || 
                res < Integer.MIN_VALUE)
                return 0;
        }
        // cast back to int from long
        return (int) res;
    }
}
