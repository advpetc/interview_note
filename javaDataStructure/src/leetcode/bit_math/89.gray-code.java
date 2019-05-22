class Solution {
    // note: grey code: two codes only differ by one bit
    // G(i) = i ^ (i / 2);
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < 1 << n; ++i) {
            // div by two == >> 1
            res.add(i ^ i >> 1);
        }
        return res;
    }
}
