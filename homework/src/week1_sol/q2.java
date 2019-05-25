package week1_sol;

import java.util.*;

public class q2 {
    static int maxLen;
    static Map<Integer, ArrayList<String>> data;

    /**
     * time O(n^2) space O(n^2)
     * @param s
     * @return
     */
    private static List<String> longestPalindrome(String s) {
        int len = s.length();
        if (len < 2) return Arrays.asList(s);
        maxLen = Integer.MIN_VALUE;
        data = new HashMap<>();
        for (int i = 0; i < len - 1; i++) {
            helper(s, i, i); // odd length
            helper(s, i, i + 1); // even length
        }
        return data.get(maxLen);
    }

    private static void helper(String s, int j, int k) {
        while (j >= 0 && k < s.length() && s.charAt(j) == s.charAt(k)) {
            j--;
            k++;
        }
        if (!data.containsKey(k - j - 1))
            data.put(k - j - 1, new ArrayList<>(Arrays.asList(s.substring(j + 1, k))));
        else
            data.get(k - j - 1).add(s.substring(j + 1, k));
        maxLen = Math.max(k - j - 1, maxLen);
    }
    public static void main(String[] args) {
        System.out.println(longestPalindrome("asas"));
        System.out.println(longestPalindrome("assass"));
        System.out.println(longestPalindrome("babad")); // aba bab
    }
}
