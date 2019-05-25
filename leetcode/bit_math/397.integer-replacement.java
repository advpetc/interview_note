class Solution {
    public int integerReplacement(int n) {
        return method2(n);
    }

    /**
     * using bit
     * if second last digit is 0, then use -1
     * else use +1
     * 1011 + 1 
     */
    private int method1(int n) {
        long N = n;
        int res = 0;
        while (N != 1) {
            if (N % 2 == 0) {
                N >>= 1; 
            } else {
                if (N == 3) {
                    res += 2;
                    break;
                }
                N = (N & 2) == 2 ? N + 1 : N - 1;
            } 
            res++;
        } 
        return res;
    }
    /**
     * n = 2k + 1
     * n + 1 = 2k + 2 / 2
     * n - 1 = k
     */
    private int method2(int n) {
        if (n == Integer.MAX_VALUE) { return 32; } 
        int res = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                if ((n + 1) % 4 == 0 && (n - 1 != 2)) {
                    n++; 
                } else {
                    n--;
                }
            }
            res++;
        }
        return res;
        
    }
}
