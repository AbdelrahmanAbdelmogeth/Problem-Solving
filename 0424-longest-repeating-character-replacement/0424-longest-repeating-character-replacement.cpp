class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> char_count;
        int l = 0;
        int no_most_freq_char = 0;
        int res = 0;
        for(int r=0; r<s.size(); r++){
            int window_size = r-l+1;
            char_count[s[r]]++;
            if(char_count[s[r]] > no_most_freq_char)
                no_most_freq_char = char_count[s[r]];
            if(window_size - no_most_freq_char <= k)
                res = max(res, window_size);
            else{
                char_count[s[l]]--; 
                l++;           
            }
        }
        return res;
    }
};