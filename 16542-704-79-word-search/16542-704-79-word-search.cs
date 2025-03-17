public class Solution {
    public bool Exist(char[][] board, string word) {
        int m = board.Length;
        int n = board[0].Length;

        int index = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(board[i][j] == word[index]){
                    if(ExistBacktrack(board, word, index, i, j, m, n))
                        return true;
                }
        return false;
    }

    public bool ExistBacktrack(char[][] board, string word, int index, int row, int col, int m, int n){
         // base case 
        if(index == word.Length) return true;

        // Checking boundaries and preventing revisiting
        if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word[index] || board[row][col] == '!')
            return false;

        // this is to prevent reusing of the same character
        char c = board[row][col];
        board[row][col] = '!'; 

        // Recursive calls in four directions
        bool found = ExistBacktrack(board, word, index + 1, row - 1, col, m, n) ||  // top
                     ExistBacktrack(board, word, index + 1, row, col + 1, m, n) ||  // right
                     ExistBacktrack(board, word, index + 1, row + 1, col, m, n) ||  // bottom
                     ExistBacktrack(board, word, index + 1, row, col - 1, m, n);    // left

        board[row][col] = c; // undo change (backtrack)

        return found;      
    }
}