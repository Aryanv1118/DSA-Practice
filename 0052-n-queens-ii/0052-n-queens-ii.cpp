class Solution {
public:
    int count = 0;
    bool isSafe(int row ,int col,vector<vector<char>>& board){
        for(int i = 0;i<=row;i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = 0;i<=col;i++){
            if(board[row][i] == 'Q'){
                return false;
            }
        }
        int r = row;
        for(int c = col;c>=0 && r>=0;c--,r--){
            if(board[r][c] == 'Q'){
                return false;
            }
        }
        r = row;
        for(int c = col;c>=0 && r<board.size();c--,r++){
            if(board[r][c] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void recur(vector<vector<char>>& board,int col){
        if(col == board.size()){
            count++;
            return;
        }
        for(int row = 0;row<board.size();row++){
            if(isSafe(row,col,board)){
                board[row][col] = 'Q';
                recur(board,col+1);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>> board (n,vector<char>(n,'.'));
        recur(board,0);
        return count;
    }
};