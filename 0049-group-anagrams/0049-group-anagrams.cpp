class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> str_strVector;
        for (auto str : strs){
            string word = str;  //we don't need to mutate the original value 
            sort(word.begin(), word.end());
            str_strVector[word].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto x : str_strVector)
           ans.push_back(x.second);
        
        return ans;
            
    }
};