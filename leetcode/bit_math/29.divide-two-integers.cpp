class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)        
            return INT_MAX;
        // long abs
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        // positive only if same sign or negative
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            // div by 2 or shift to left by one
            while (temp << 1 <= dvd) {
                temp <<= 1; 
                // times 2
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};
