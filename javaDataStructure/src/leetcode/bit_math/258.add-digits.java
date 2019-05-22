class Solution {
    public int addDigits(int num) {
        // return method1(num);
        return method2(num);
    }

    private int method1(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum >= 10) {
            return method1(sum);
        } else {
            return sum; 
        }
    }

    private int method2(int num) {
        return (num - 1) % 9 + 1;
    }
}
