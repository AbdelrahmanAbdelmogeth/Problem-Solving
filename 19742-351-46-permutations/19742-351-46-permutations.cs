public class Solution {
    private IList<IList<int>> PermutationResult = new List<IList<int>>();

    public IList<IList<int>> Permute(int[] nums) {
        PermuteBacktrack(0, nums);
        return PermutationResult;
    }

    private void PermuteBacktrack(int index, int[] nums){
        if(index == nums.Length){
            PermutationResult.Add(new List<int>(nums));
            return;
        }

        for(int i=index; i<nums.Length; i++){
            Swap(nums, index, i);
            PermuteBacktrack(index + 1, nums);
            Swap(nums, index, i);
        }
    }

    // Function to swap elements in the array
    private void Swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}