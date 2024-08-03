public class Solution {
    public int FindMin(int[] nums) {
        int n = nums.Length;
    int low = 0;
    int high = n - 1;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] < nums[high]) {
            // Rotation point is on the left side
            high = mid;
        } else {
            // Rotation point is on the right side
            low = mid + 1;
        }
    }
    
    return nums[low];
    }
}