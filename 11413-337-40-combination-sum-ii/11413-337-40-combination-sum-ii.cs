public class Solution {
    private List<IList<int>> CombinationResult = new List<IList<int>>(); 
    private List<int> Path = new List<int>();

    public IList<IList<int>> CombinationSum2(int[] candidates, int target) {
        Array.Sort(candidates);  // Sorting ensures we handle duplicates correctly
        CombinationSum2Backtrack(0, candidates, target);
        return CombinationResult;
    }

    private void CombinationSum2Backtrack(int index, int[] candidates, int target){
        if(target == 0){
            CombinationResult.Add(new List<int>(Path)); // Found a valid combination
            return;     
        }

        for(int i = index; i < candidates.Length; i++){
            // Skip duplicate elements within the same recursion level
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break; // Stop if the number is greater than the remaining target
            
            Path.Add(candidates[i]);
            CombinationSum2Backtrack(i + 1, candidates, target - candidates[i]); // Move to the next element
            Path.RemoveAt(Path.Count - 1); // Backtrack
        }
    }
}
