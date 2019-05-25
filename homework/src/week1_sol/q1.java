package week1_sol;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class q1 {

    /**
     * time: O(n^2), space: O(n)
     * @param nums
     * @param target
     * @return
     */
    public static List<int[]> twoSum(int[] nums, int target) {
        List<int[]> ret = new ArrayList<>();
        int n = nums.length;
        if (n < 2) return ret;
        Map<Integer, Integer> map = new HashMap<>(); // key: nums[i], value: count
        for (int i = 0; i < n; i++) {
            int key1 = nums[i], key2 = target - nums[i];
            if (map.containsKey(key2) && map.get(key2) > 0) { // both exist
                int[] pair = {key1, key2};
                if (!ret.contains(pair)) ret.add(pair); // check if in the ret already: O(n)
                map.put(key2, map.get(key2) - 1);
            } else {
                if (!map.containsKey(key1)) map.put(key1, 1);
                else                        map.put(key1, map.get(key1) + 1);
            }
        }
        return ret;
    }          
    private static void print(List<int[]> ret) {
        for (int i = 0; i < ret.size(); i++) {
            System.out.println(ret.get(i)[0]);
            System.out.println(ret.get(i)[1]);
            System.out.println("======");
        }
        System.out.println("end\n");
    }
    public static void main(String[] args) {
        List<int[]> ret1 = twoSum(new int[]{1, 1, 2, 2, 3}, 4);
        List<int[]> ret2 = twoSum(new int[]{4, 1, 1, 2, 2, 3}, 4);
        List<int[]> ret3 = twoSum(new int[]{0, 4, 1, 1, 2, 2, 3}, 4);
        List<int[]> ret4 = twoSum(new int[]{4}, 4);
        print(ret1);
        print(ret2);
        print(ret3);
        print(ret4);
    }


}
