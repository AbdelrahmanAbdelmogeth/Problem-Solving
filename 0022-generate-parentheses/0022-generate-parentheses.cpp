void generate_parenthesis(string& str, int no_of_openning_tags, int no_of_closing_tags, int no_of_pairs, vector<string>& str_vector){
    // base case
    if(no_of_closing_tags == no_of_pairs){
         str_vector.push_back(str);
         return;   
    }

    if(no_of_openning_tags < no_of_pairs){
        string str1 = str + '(';
        generate_parenthesis(str1, no_of_openning_tags + 1, no_of_closing_tags, no_of_pairs, str_vector);
    }
    
    if(no_of_closing_tags < no_of_openning_tags){
      string str2 = str + ')';
      generate_parenthesis(str2, no_of_openning_tags , no_of_closing_tags + 1, no_of_pairs, str_vector);
    }     
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "(";
        generate_parenthesis(str, 1, 0, n, res);
        return res;
        
    }
};