class Solution {
public:
    bool isSafe(char x,vector<vector<char>>& board,int row,int col){
        for(int i = 0;i<9;i++){
            if(board[row][i] == x)
                return false;
        }
        for(int j = 0;j<9;j++){
            if(board[j][col] == x)
                return false;
        }
        int startRow = (row/3)*3;
        int startCol = (col/3)*3;
        for(int i = 0;i<3;i++){
           for(int j = 0;j<3;j++){
                if(board[startRow+i][startCol+j]==x){
                    return false;
               }
           } 
        }
        return true;
    }
    bool recur(vector<vector<char>>& board,int row,int col){
        if(row == 9)
            return true;
        int newRow = row;
        int newCol = col+1;
        if(newCol == 9){
            newRow = row+1;
            newCol = 0;
        }
        if(board[row][col] != '.'){
            return recur(board,newRow,newCol);
        }
        for(char i = '1';i<='9';i++){
            if(isSafe(i,board,row,col)){
                board[row][col] = i;
                if(recur(board,newRow,newCol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        recur(board,0,0);
    }
};