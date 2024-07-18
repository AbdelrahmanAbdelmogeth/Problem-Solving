class Solution {
public:
    bool isPalindrome(string s) {
        int start_index = 0, end_index = s.size() - 1;
        while(start_index <= end_index){
            if(!isalnum(s[start_index]))    //not alfanumeric char then we ignore it and continue to next char 
                {start_index++; continue;}
            if(!isalnum(s[end_index]))      //not alfanumeric char then we ignore it and continue to prev char
                {end_index--; continue;}
            if(tolower(s[start_index]) != tolower(s[end_index]))
                return false;
            start_index++;
            end_index--;
        }
        return true;
    }
};