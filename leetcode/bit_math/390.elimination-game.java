class Solution {
    /**
     * n = 8,
     * 1 2 3 4 5 6 7 8
     *   2   4   6   8
     *   2       6
     *           6
     */
    public int lastRemaining(int n) {
        boolean left = true;
        int remaining = n;
        int step = 1;
        int res = 1; // head
        while (remaining > 1) {
            if (left || remaining % 2 == 1) {
                res = res + step;
            } 
            remaining = remaining / 2;
            step *= 2;
            left = !left;
        }
        return res;
    }
}
