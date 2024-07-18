#define LESS_SPACE_COMPLEXITY 1

#if LESS_SPACE_COMPLEXITY == 0
struct index_height{
    int index;
    int height;
};
#endif

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        #if LESS_SPACE_COMPLEXITY == 0
        stack<index_height> ind_h;
        int n = heights.size();
        int max_area = INT_MIN;
        int start_index;
        for(int i=0; i<n; i++){
            start_index = i;
            while(ind_h.size() && ind_h.top().height > heights[i]){
                max_area = max(max_area, ind_h.top().height * (i - ind_h.top().index));
                start_index = ind_h.top().index; 
                ind_h.pop();
            }
            ind_h.push({start_index, heights[i]});
        }
        while(ind_h.size()){
            max_area = max(max_area, ind_h.top().height * (n - ind_h.top().index));
            ind_h.pop();
        }
        return max_area;
        #endif
        
        #if LESS_SPACE_COMPLEXITY == 1
        // enhance the space complexity a little bit store only the index
        stack<int> index_st;
        int n = heights.size();
        int max_area = INT_MIN;
        for(int i=0; i<n; i++){
            while(index_st.size() && heights[index_st.top()] > heights[i]){
                int idx = index_st.top(); index_st.pop();
                int curr_area = heights[idx] * (index_st.empty() ? i : (i - index_st.top() - 1));
                max_area = max(max_area, curr_area);
            }
            index_st.push(i);
        }
        while(index_st.size()){
            int idx = index_st.top(); index_st.pop();
            int curr_area = heights[idx] * (index_st.empty() ? n : (n - index_st.top() - 1));
            max_area = max(max_area, curr_area);
        }
        return max_area;
        #endif
    }
};