public class Solution {
    public int MissingNumber(int[] nums) {
        int res = 0; int AllRange = 0;
        int n = nums.Count();

        for(int i=0; i<=n; i++)
            AllRange ^= i;

        foreach(var num in nums)
            res ^= num;

        return res ^ AllRange;    
    }
}