public class Solution {
    public int SingleNumber(int[] nums) {
        int res = nums[0];
        for(int i=1; i<nums.Count(); i++){
            res ^= nums[i];
        }
        return res;
    }
}