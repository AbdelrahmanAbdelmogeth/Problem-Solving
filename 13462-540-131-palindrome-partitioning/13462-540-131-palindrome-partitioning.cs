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