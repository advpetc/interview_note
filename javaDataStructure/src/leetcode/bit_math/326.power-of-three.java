class Solution {
    public boolean isPowerOfThree(int n) {
        return method2(n);
    }
    private boolean method1(int n) {
        if (n <= 0) { return false; } 
        while (n % 3 == 0) { n /= 3; }
        return n == 1;
    }

    private boolean method2(int n) {
        return (Math.log10(n) / Math.log10(3)) % 1 == 0;
    }
}
