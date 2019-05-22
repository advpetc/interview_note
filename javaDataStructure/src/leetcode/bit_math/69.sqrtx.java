class Solution {

    public int mySqrt(int x) {
        return method2(x);
    }
    
    /**
     * time: O(logn)
     * space: O(1)
     */
    private int method2(int x) {
        if (x <= 0) return 0;
        int low = 1, high = x;
        while (low <= high) {
            long mid = (high - low) / 2 + low;
            if (mid * mid == x)
                return (int) mid;
            else if (mid * mid < x) {
                low = (int) mid + 1;
            } else {
                high = (int) mid - 1;
            }
        }
        if (high * high < x)
            return (int) high;
        else
            return (int) low;
    }

    private int method1(int x) {
        long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        return (int) r;
    }
}
