class Solution {
    /**
     * 1 - true
     * 2 - true
     * 3 - true
     * 4 - false
     * 5 - true
     * 6 - true
     * 7 - true
     * 8 - false
     */
    public boolean canWinNim(int n) {
        return n % 4 != 0; 
    }
}
