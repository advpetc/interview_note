package week1_sol;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;

public class q3 {
    public static int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(l -> l[0]));
        LinkedList<int[]> ret = new LinkedList<>();
        for (int[] row: intervals) {
            if (ret.isEmpty() || ret.getLast()[1] < row[0]) {
                ret.add(row);
            } else {
                ret.getLast()[1] = Math.max(ret.getLast()[1], row[1]);
            }
        }
        int[][] retval = ret.stream().toArray(int[][]::new);
        int totalTime = 0;
        for (int[] interval : retval) {
            totalTime += (interval[1] - interval[0]);
        }
        System.out.println("total time is:" + totalTime);
        return retval;
    }

    private static void print(int[][] ret) {
        for (int[] row: ret) {
            System.out.println(row[0] + " " + row[1]);
        }
        System.out.println("===");
    }
    public static void main(String[] args) {
        int[][] test1 = {{3, 4}, {1, 6}};
        int[][] test2 = {{3, 4}, {1, 6}, {4, 5}, {-1, 20}};
        int[][] test3 = {{3, 4}, {1, 6}, {1, 6}};
        int[][] test4 = {{3, 4}, {1, 6}, {1, 2}};
        print(merge(test1)); // {1, 6} 5
        print(merge(test2)); // {-1, 20} 21
        print(merge(test3)); // {1, 6} 5
        print(merge(test4)); // {1, 6} 5
    }
}
