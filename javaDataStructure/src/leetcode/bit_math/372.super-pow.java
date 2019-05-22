class Solution {
    /**
     * (a * b) % c = (a % c) * (b % c)
     * a^32 = a^30 * a^2
     * (a * a) % c = (a % c) * (a % c)
     */
    public int superPow(int a, int[] b) {
        
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
