class Solution {
    /**
     * (a * b) % c = (a % c) * (b % c)
     * a^32 = a^30 * a^2
     * (a * a) % c = (a % c) * (a % c)
     */
    public int superPow(int a, int[] b) {
        return superPow(a, b, b.length, 1337);
    }
    /**
     * length: num of digits for power (b)
     */
    private int superPow(int a, int[] b, int length, int k) {
        if (length == 1) { return powMode(a, b[0], k); } 
        return powMode(superPow(a, b, length - 1, k), 10, k) *  // (a % c)
               powMode(a, b[length - 1], k) % k; // (a % c)
    }

    private int powMode(int x, int y, int k) {
        x %= k;
        int pow = 1;
        for (int i = 0; i < y; i++) {
            pow = pow * x % k; 
        }
        return pow;
    }
}
