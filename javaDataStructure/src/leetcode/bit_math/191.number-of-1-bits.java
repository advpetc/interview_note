public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        return method2(n);
    }

    /**
     * 001011: n
     * 000001: 1 &
     *      1
     */
    private int method1(int n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }

    private int method2(int n) {
        int res = 0;
        while (n != 0) {
            n &= (n - 1);
            res++;
        }
        return res;
    }
}
