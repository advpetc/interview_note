package week1_sol;

import java.util.*;

public class q4 {
    // return the most *intersected* interval(s)
    public static int[][] merge2(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(l -> l[0]));
        HashMap<int[], Integer> map = new HashMap<>();
        LinkedList<int[]> ret = new LinkedList<>();
        int maxFreq = Integer.MIN_VALUE;
        for (int[] row: intervals) {
            if (ret.isEmpty() || ret.getLast()[1] < row[0]) {
                ret.add(row);
            } else {
                // TODO
                map.put(row, map.get(row) + 1);
                maxFreq = Math.min(maxFreq, map.get(row));
                ret.getLast()[1] = Math.max(ret.getLast()[1], row[1]);
            }
        }
        int[][] retval = ret.stream().toArray(int[][]::new);
        return retval;
    }
    
    

    private static void print(int[][] ret) {
        for (int[] row : ret) {
            System.out.println(row[0] + " " + row[1]);
        }
        System.out.println("===");
    }

    public static void main(String[] args) {
        int[][] test1 = {{3, 4}, {1, 6}};
        int[][] test2 = {{3, 4}, {1, 6}, {4, 5}, {-1, 20}};
        int[][] test3 = {{3, 4}, {1, 6}, {1, 6}};
        int[][] test4 = {{3, 4}, {1, 6}, {1, 2}};
        print(merge2(test1)); // {1, 6} 5
        print(merge2(test2)); // {-1, 20} 21
        print(merge2(test3)); // {1, 6} 5
        print(merge2(test4)); // {1, 6} 5
    }
}
