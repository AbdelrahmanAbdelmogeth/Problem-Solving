class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> char_count_s;
        unordered_map<char, int> char_count_t;
        for(auto x:s)
            char_count_s[x]++;
        for(auto x:t)
            char_count_t[x]++;

        for(auto x:char_count_s)
            if(x.second != char_count_t[x.first])
                return false;
            
        if(char_count_s.size() == char_count_t.size())    
            return true;
        return false;                   
    }
};