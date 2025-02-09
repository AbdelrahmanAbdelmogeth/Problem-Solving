public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        if (s1.Length > s2.Length) return false;

        // Create frequency arrays for both strings
        int[] s1Map = new int[26];
        int[] s2Map = new int[26];

        // Populate the frequency map for s1 and the first window of s2
        for (int i = 0; i < s1.Length; i++) {
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }

        // Count initial matches
        int matches = 0;
        for (int i = 0; i < 26; i++)
            if (s1Map[i] == s2Map[i])
                matches++;

        // Sliding window technique
        int left = 0;
        for (int right = s1.Length; right < s2.Length; right++) {
            if (matches == 26)
                return true;

            // Add new character to the window
            int index = s2[right] - 'a';
            s2Map[index]++;
            if (s1Map[index] == s2Map[index])
                matches++;
            else if (s1Map[index] + 1 == s2Map[index]) // means the s2 exceed number of chars in s1 (no match anymore)
                matches--;

            // Remove old character from the window
            index = s2[left] - 'a';
            s2Map[index]--;
            if (s1Map[index] == s2Map[index])
                matches++;
            else if (s1Map[index] - 1 == s2Map[index])
                matches--;

            left++;
        }

        return matches == 26;
    }
}

/*
          ┌──────────────┐
          │ Start        │
          └────┬─────────┘
               ▼
     ┌───────────────────────────┐
     │ Check if len(s1) > len(s2)│
     └──────────┬────────────────┘
                ▼
        Yes ┌────────┐ No
            │ Return │───────────┐
            │ false  │           ▼
            └────────┘  ┌──────────────────────────────┐
                        │ Initialize two frequency     │
                        │ arrays s1Map & s2Map [26]    │
                        └──────────────────────────────┘
                                        ▼
                        ┌──────────────────────────────┐
                        │ Fill frequency arrays for    │
                        │ s1 and first window of s2    │
                        └──────────────────────────────┘
                                        ▼
                        ┌──────────────────────────────┐
                        │ Count initial character      │
                        │ matches (s1Map == s2Map)     │
                        └──────────────────────────────┘
                                        ▼
                        ┌──────────────────────────────┐
                        │ Sliding window iteration     │
                        │ through s2                   │
                        └──────────────────────────────┘
                                        ▼
                      ┌───────────────────────────┐
                      │ matches == 26 ?           │
                      └────────────┬──────────────┘
                   Yes ▼        No ▼
               ┌──────────┐  ┌──────────────────┐
               │ Return   │  │ Slide the window │
               │ true     │  └──────────────────┘
               └──────────┘            ▼
                                ┌──────────────────────┐
                                │ Add new character    │
                                ├──────────────────────┤
                                │ If s1Map[index] ==   │
                                │ s2Map[index],        │
                                │ Increment matches++  │
                                ├──────────────────────┤
                                │ If s1Map[index] + 1  │
                                │ == s2Map[index],     │
                                │ Decrement matches--  │
                                └──────────────────────┘
                                            ▼
                                ┌──────────────────────┐
                                │ Remove old character │
                                ├──────────────────────┤
                                │ If s1Map[index] ==   │
                                │ s2Map[index],        │
                                │ Decrement matches--  │
                                ├──────────────────────┤
                                │ If s1Map[index] - 1  │
                                │ == s2Map[index],     │
                                │ Increment matches++  │
                                └──────────────────────┘
                                            ▼
                                ┌──────────────────────┐
                                │ Move window forward  │
                                └──────────────────────┘
                                            ▼
                         ┌────────────────────────┐
                         │ Loop until s2 is done  │
                         │ If matches == 26, true │
                         └─────────┬──────────────┘
                                   ▼
                            ┌─────────┐
                            │ Return  │
                            │ false   │
                            └─────────┘
*/