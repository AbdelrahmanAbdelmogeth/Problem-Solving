public class Solution {
    private List<IList<int>> SubsetsResult = new List<IList<int>>();

    public IList<IList<int>> SubsetsWithDup(int[] nums) {
        Array.Sort(nums); // Sort the array to handle duplicates
        GenerateSubsets(0, nums, new List<int>());
        return SubsetsResult;
    }

    private void GenerateSubsets(int index, int[] nums, List<int> CurrentSubset){
        // Add the current subset to the result
        SubsetsResult.Add(new List<int>(CurrentSubset)); // append the current subset to the result
        /*
            Iterate through the elements starting from the index given
        */
        for(int i=index; i<nums.Length; i++){ 
            // Skip duplicates to avoid generating duplicate subsets
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            CurrentSubset.Add(nums[i]); // include the element in the current subset
            GenerateSubsets(i+1, nums, CurrentSubset); // make the recursive call with current subset starting from index i+1 to include the next element and so on
            CurrentSubset.RemoveAt(CurrentSubset.Count - 1); // remove the element that we included in the recursive call to include the one after it in the next iteration
        }
    }
}