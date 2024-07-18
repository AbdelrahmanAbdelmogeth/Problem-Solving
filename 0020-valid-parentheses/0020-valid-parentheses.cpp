bool Matchc(char open, char close){
    if (open == '[' && close == ']')
        return true;
    if (open == '{' && close == '}')
        return true;
    if (open == '(' && close == ')')
        return true;
    return false;
}

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1)
            return false;
        
        stack<char> openning_brackets_stack;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                openning_brackets_stack.push(s[i]);
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(openning_brackets_stack.size() == 0)
                    return false;
                if(Matchc(openning_brackets_stack.top(), s[i])){
                    openning_brackets_stack.pop();
                }
                else
                    return false;
            }
        }
        if (!openning_brackets_stack.size())
            return true;
        
        return false;
    }
};