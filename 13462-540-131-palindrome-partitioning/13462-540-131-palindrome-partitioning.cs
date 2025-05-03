public class Solution {
    private List<IList<string>> PalindromePartitions = new List<IList<string>>();

    public IList<IList<string>> Partition(string s) {
        GeneratePalindromePartitions(0, s, new List<string>());
        return PalindromePartitions;
    }

    private void GeneratePalindromePartitions(int index, string s, List<string> Partitions){
        if(index == s.Length){
            PalindromePartitions.Add(new List<string>(Partitions));
            return;
        }

        for (int i = index; i < s.Length; i++) {
            if (IsPalindrome(s, index, i)) {
                // Add the current palindromic substring
                Partitions.Add(s.Substring(index, i - index + 1));
                // Recurse for the rest of the string
                GeneratePalindromePartitions(i + 1, s, Partitions);
                // Backtrack
                Partitions.RemoveAt(Partitions.Count - 1);
            }
        }
    }

    private bool IsPalindrome(string str, int i, int j)
    {
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

}



/*
Start with index = 0, partitions = []

├── Try "a" (s[0:1]) → Palindrome ✅
│   └── partitions = ["a"]
│
│   ├── Try "a" (s[1:2]) → Palindrome ✅
│   │   └── partitions = ["a", "a"]
│   │
│   │   ├── Try "b" (s[2:3]) → Palindrome ✅
│   │   │   └── partitions = ["a", "a", "b"]
│   │   │   └── index == 3 → END → ✅ add ["a", "a", "b"]
│   │   │   └── Backtrack: remove "b" → ["a", "a"]
│   │
│   │   └── Backtrack: remove "a" → ["a"]
│
│   ├── Try "ab" (s[1:3]) → Not Palindrome ❌
│
│   └── Backtrack: remove "a" → []

├── Try "aa" (s[0:2]) → Palindrome ✅
│   └── partitions = ["aa"]
│
│   ├── Try "b" (s[2:3]) → Palindrome ✅
│   │   └── partitions = ["aa", "b"]
│   │   └── index == 3 → END → ✅ add ["aa", "b"]
│   │   └── Backtrack: remove "b" → ["aa"]
│
│   └── Backtrack: remove "aa" → []

├── Try "aab" (s[0:3]) → Not Palindrome ❌

Done.
*/
