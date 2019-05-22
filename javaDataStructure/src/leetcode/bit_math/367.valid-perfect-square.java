class Solution {
    public boolean isPerfectSquare(int num) {
        return method4(num);
    }

    /**
     * time O(n); space O(1)
     */
    private boolean method1(int num) {
        if (num < 0) return false;
        if (num == 1) return true;
        for (int i = 1; i <= num / i; ++i) {
            if (i * i == num) return true;
        }
        return false;
    }

    /**
     * time O(logn) space O(1)
     */
    private boolean method2(int num) {
        int low = 1, high = num;
        while (low <= high) {
            long mid = (high - low) / 2 + low;
            if (mid * mid == num) {
                return true; 
            } else if (mid * mid < num) {
                low = (int) mid + 1; 
            } else {
                high = (int) mid - 1;
            }
        }
        return false;
    }

    /**
     * 1 = 1
     * 4 = 1 + 3
     * 9 = 1 + 3 + 5 
     * time: O(n) space: O(1)
     */
    private boolean method3(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }

    /**
     * newtown method: O()
     * x(n+1) = 1/2 (x(n) + n / x(n))
     */
    private boolean method4(int num) {
        long x = num;
        while (x * x > num) {
            x = (x + num / x) / 2;
        }
        return x * x == num;
    }
}
