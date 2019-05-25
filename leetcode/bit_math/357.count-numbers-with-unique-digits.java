class Solution {
    /*
     * n is num of digits
     * n = 1: 10
     * n = 2: 9 * 9
     * n = 3: f(2) * 8 = 9 * 9 * 8
     * time: 1, space: 1
     */
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1; 
        }
        int res = 10;
        int uniqueDigits = 9;
        int avaliable = 9;
        while (n-- > 1 && avaliable > 0) {
            uniqueDigits = uniqueDigits * avaliable;
            res += uniqueDigits;
            avaliable--;
        } 
        return res;
         
    }
}
