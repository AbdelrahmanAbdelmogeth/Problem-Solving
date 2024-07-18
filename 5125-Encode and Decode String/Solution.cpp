class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str;
        for(auto str: strs){
            for (char c : str)
                encoded_str += c;

            encoded_str += '~';
            cout<<encoded_str;    
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        string str;
        for(char c: s){
            if(c != '~')
                str += c;
            else{
                decoded_strs.push_back(str); 
                str.clear();
            }
        }
        return decoded_strs;
    }
};
