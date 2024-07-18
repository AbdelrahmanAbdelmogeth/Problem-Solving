struct temp_index{
    int temp;
    int index;
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<temp_index> temp_index_st;
        for(int i=0; i<n; i++){
            while(temp_index_st.size() && temp_index_st.top().temp < temperatures[i]){
                res[temp_index_st.top().index] = i - temp_index_st.top().index;
                temp_index_st.pop();
            }
            temp_index_st.push({temperatures[i], i});
        }
        return res;
    }
};