package hashtable;

import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public boolean containsDuplicate(int[] nums) {
//        return hashSet(nums);
        return hashMap(nums);
    }
    private boolean hashMap(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            if (map.containsKey(num))
                return true;
            else
                map.put(num, 1);
        }
        return false;
    }
    private boolean hashSet(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; ++i) {
            if (!set.add(nums[i]))
                return true;
        }
        return false;
    }
}
