class Solution {
    public double myPow(double x, int n) {
        if (n > 0) {
            return pow(x, n);
        } else {
            return 1.0 / pow(x, n);
        } 
    }
    private void pow(double x, int n) {
        if (n == 0) {
            return 1; 
        } 
        double y = pow(x, n / 2);
        if (n % 2 == 0) {
           return y * y; 
        } else {
            return y * y * y;
        }
    }


    private void method2() {
        if (n == 0) {
            return 1; 
        }
        double res = 1;
        long abs = Math.abs((long) n);
        while (abs > 0) {
            if (abs % 2 != 0) {
                res *= x; 
            } 
            x *= x;
            abs /= 2;
        }
        if (n < 0) {
            return 1.0 / res; 
        }
        return res;
    }
}
