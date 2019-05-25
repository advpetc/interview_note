package week1_sol;

import java.util.ArrayList;
import java.util.Collections;

public class q5 {
    public static void sortColors(int[] colors, int k) {
        // k-way partitioning
        // using bucket sort
        int global_max = Integer.MIN_VALUE;
        int global_min = Integer.MAX_VALUE;
        // find the largest and min value from nums
        for (int n : colors)
        {
            global_max = Math.max(global_max, n);
            global_min = Math.min(global_min, n);
        }
        int bucketNum = (global_max - global_min) / k;
//        vector<vector<int>> bucket(bucketNum, vector<int>(0));
//        ArrayList<ArrayList<Integer>> bucket = new ArrayList<>();
        int[][] bucket = new int[bucketNum][];

        // insert into bucket
        for (int n : colors)
        {
            int index = (n - global_min) / colors.length;
//            bucket[index](n);
        }

        // sort each bucket
//        for (ArrayList<Integer> b : bucket)
//            Collections.sort(b);
        System.out.println(bucket);
    }

    public static void main(String[] args) {

    }
}
