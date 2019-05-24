class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<Integer>();    
        int squareSum, remain;
        // return true means not inside set yet
        while (set.add(n)) {
            squareSum = 0;
            while (n > 0) {
                remain = n % 10;
                squareSum += remain * remain;
                n /= 10;
            }
            if (squareSum == 1) { return true; }
            else { n = squareSum; }
        }
        return false;
    }
}
