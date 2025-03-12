/*
    Imagine you are in a maze (a target number) and you need to find all possible ways to reach the exit (sum = target).

        You can move forward (choose a number).
        You can go back if you hit a dead end (backtracking).
        You keep exploring until you find a way out (sum == target).

*/

public class Solution {
    private List<IList<int>> CombinationList = new List<IList<int>>(); // Store the result
    private List<int> Path = new List<int>(); // Store the current numbers we have picked

    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        GenerateCombinationsBacktrack(0, candidates, target);
        return CombinationList;
    }

    private void GenerateCombinationsBacktrack(int index, int[] candidates, int target){
        // base cases
        if(target == 0){
            CombinationList.Add(new List<int>(Path)); // add a combination to the list
            return;
        }

        if (target < 0){ // this means we can't find a target there we went beyond the target
            return;
        }

        for(int i = index; i < candidates.Length; i++){
            Path.Add(candidates[i]);
            GenerateCombinationsBacktrack(i ,candidates, target - candidates[i]); // i choose the same i to take the candidate[i] again and again 
            Path.RemoveAt(Path.Count - 1);
        }
    }
}