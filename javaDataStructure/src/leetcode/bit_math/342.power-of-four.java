class Solution {
    public boolean isPowerOfFour(int num) {
        // return method1(num);
        return method2(num);
    }

    private boolean method1(int n) {
        if (n > 1) {
            while (n % 4 == 0)
                n /= 4;
        }
        return n == 1;
    }

    private boolean method2(int num) {
        return (Math.log(num) / Math.log(4)) % 1 == 0;
    }
}
