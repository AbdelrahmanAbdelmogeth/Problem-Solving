class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row_set(9);
        vector<unordered_set<int>> col_set(9);
        vector<unordered_set<int>> box_set(9);
        
        //i represents the row and j represents the column
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    //check if it's present in the row,col and box sets that should belong to
                    if(row_set[i].find(board[i][j]) != row_set[i].end() ||
                       col_set[j].find(board[i][j]) != col_set[j].end() ||
                       box_set[(i/3*3) + (j/3)].find(board[i][j]) != box_set[(i/3*3) + (j/3)].end())
                        return false;
                    else{
                        row_set[i].insert(board[i][j]);
                        col_set[j].insert(board[i][j]);
                        box_set[(i/3*3) + (j/3)].insert(board[i][j]);
                    }
                        
                }
            }
        }
        
        return true;
    }
};