class Solution {
    public int maxProduct(String[] words) {
        int res = 0;
        int[] bytes = new int[words.length];
        for (int i = 0; i < words.length; ++i) {
            int val = 0;
            for (int j = 0; j < words[i].length(); ++j) {
                /*
                 * 1 << 0 0001 1 a
                 1 << 1 00010 2 b 
                 1 << 2 00100 4 c
                 abc = 00111 = 7
                 */
                val |= 1 << (words[i].charAt(j) - 'a'); 
            }
            bytes[i] = val;
        }
        for (int i = 0; i < bytes.length; ++i) {
            for (int j = i + 1; j < bytes.length; ++j) {
                // share common letters
                if ((bytes[i] & bytes[j]) == 0)
                    res = Math.max(res, words[i].length() * words[j].length());
            } 
        }
        return res;
    }
}
