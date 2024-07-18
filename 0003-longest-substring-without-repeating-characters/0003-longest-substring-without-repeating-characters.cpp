class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)
            return s.size();
        
        unordered_set<char> char_set;
        int l = 0;
        
        int max_length_of_longest_substring = INT_MIN;
        for(int r=0; r<s.size(); r++){
            while(char_set.find(s[r]) != char_set.end()){
                char_set.erase(s[l]);
                l++;
            }
            max_length_of_longest_substring = max(max_length_of_longest_substring, (r-l+1));
            char_set.insert(s[r]);
        }
        return max_length_of_longest_substring;
    }
};