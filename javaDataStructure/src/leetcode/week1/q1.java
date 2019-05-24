package leetcode.week1;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class q1 {

    public static List<int[]> twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : nums) {
            if (map.containsKey(target - n)) {
                if (map)
            } 
        }
    }          
          
    public static void main() {
        List<int[]> ret = twoSum(new int[]{1, 1, 2, 2, 3}, 4);
        for (int i = 0; i < ret.size(); i++) {
            System.out.println(ret.get(i)); 
        } 
    }


}
