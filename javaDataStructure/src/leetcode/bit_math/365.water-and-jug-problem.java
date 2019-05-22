class Solution {
    /**
     * x * m + y * n = z
     * z = gcd(x,y) * i
     * z % gcd(x,y) = 0 then m and n exist
     * time ~= O(1)
     * space = O(n)
     */
    public boolean canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == z || y == z || x + y == 2) return true;
        return z % gcd(x, y) == 0;
    }
    private int gcd(int a, int b) {
        if (b == 0) {
            return a; 
        } 
        return gcd(b, a % b);
    }
}
