#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*"){
                values.push(stoi(tokens[i]));
            }else{
                 int right = values.top();
                 values.pop();
                 int left = values.top();
                 values.pop();
                 
                 int res;
                 if(tokens[i] == "+")
                     res = left + right;
                 if(tokens[i] == "-")
                     res = left - right;
                 if(tokens[i] == "*")
                     res = left * right;
                 if(tokens[i] == "/")
                     res = left / right;
                 
                 values.push(res);
             }
                    
        }
        return values.top();
    }
};