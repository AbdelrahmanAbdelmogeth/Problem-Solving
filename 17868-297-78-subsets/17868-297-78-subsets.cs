public class Solution {
    private List<IList<int>> SubsetsResult = new List<IList<int>>();
    public IList<IList<int>> Subsets(int[] nums) {
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
            CurrentSubset.Add(nums[i]); // include the element in the current subset
            GenerateSubsets(i+1, nums, CurrentSubset); // make the recursive call with current subset starting from index i+1 to include the next element and so on
            CurrentSubset.RemoveAt(CurrentSubset.Count - 1); // remove the element that we included in the recursive call to include the one after it in the next iteration
        }
    }
}

/*
Call: GenerateSubsets(0, nums, [])
--------------------------------------
index = 0, CurrentSubset = []
- Add [] to the result

Loop iteration i=0
  Add nums[0] = 1 -> CurrentSubset = [1]
  Call GenerateSubsets(1, nums, [1])

  --------------------------------------
  index = 1, CurrentSubset = [1]
  - Add [1] to the result

  Loop iteration i=1
    Add nums[1] = 2 -> CurrentSubset = [1,2]
    Call GenerateSubsets(2, nums, [1,2])

    --------------------------------------
    index = 2, CurrentSubset = [1,2]
    - Add [1,2] to the result

    Loop iteration i=2
      Add nums[2] = 3 -> CurrentSubset = [1,2,3]
      Call GenerateSubsets(3, nums, [1,2,3])

      --------------------------------------
      index = 3 (Base Case: Exceeds length)
      - Add [1,2,3] to the result
      - Return (backtrack)
      --------------------------------------

    Backtrack: Remove nums[2] -> CurrentSubset = [1,2]
    End loop i=2
    --------------------------------------

  Backtrack: Remove nums[1] -> CurrentSubset = [1]
  
  Loop iteration i=2
    Add nums[2] = 3 -> CurrentSubset = [1,3]
    Call GenerateSubsets(3, nums, [1,3])

    --------------------------------------
    index = 3 (Base Case: Exceeds length)
    - Add [1,3] to the result
    - Return (backtrack)
    --------------------------------------

  Backtrack: Remove nums[2] -> CurrentSubset = [1]
  End loop i=2
  --------------------------------------

Backtrack: Remove nums[0] -> CurrentSubset = []

Loop iteration i=1
  Add nums[1] = 2 -> CurrentSubset = [2]
  Call GenerateSubsets(2, nums, [2])

  --------------------------------------
  index = 2, CurrentSubset = [2]
  - Add [2] to the result

  Loop iteration i=2
    Add nums[2] = 3 -> CurrentSubset = [2,3]
    Call GenerateSubsets(3, nums, [2,3])

    --------------------------------------
    index = 3 (Base Case: Exceeds length)
    - Add [2,3] to the result
    - Return (backtrack)
    --------------------------------------

  Backtrack: Remove nums[2] -> CurrentSubset = [2]
  End loop i=2
  --------------------------------------

Backtrack: Remove nums[1] -> CurrentSubset = []

Loop iteration i=2
  Add nums[2] = 3 -> CurrentSubset = [3]
  Call GenerateSubsets(3, nums, [3])

  --------------------------------------
  index = 3 (Base Case: Exceeds length)
  - Add [3] to the result
  - Return (backtrack)
  --------------------------------------

Backtrack: Remove nums[2] -> CurrentSubset = []
End loop i=2
--------------------------------------

result in order

[
  [],       // Empty subset
  [1],      
  [1,2],    
  [1,2,3],  
  [1,3],    
  [2],      
  [2,3],    
  [3]       
]

*/