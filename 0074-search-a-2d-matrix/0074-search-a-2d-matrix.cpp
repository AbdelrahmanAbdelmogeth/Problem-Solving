class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0, high = row * col - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int tC = mid % col;
            int tR = mid / col;
            
            if(matrix[tR][tC] == target)
                return true;
            else if(matrix[tR][tC] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
        
    }
};