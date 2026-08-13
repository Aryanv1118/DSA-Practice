class Solution {
public:
    bool match = false;
    vector<vector<bool>>used;
    void backtrack(vector<vector<char>>& board,string &word,int idx,int x,int y){
        int n = board.size();
        int m = board[0].size();
        if(word[idx] != board[x][y])
            return;

    if(idx == word.length()-1){
        match = true;
        return;
    }
        used[x][y] = true;
        if((x > 0 && !used[x-1][y]) && board[x-1][y] == word[idx+1])             
            backtrack(board,word,idx+1,x-1,y);        
        if((x < n-1 && !used[x+1][y]) && board[x+1][y] == word[idx+1])             
            backtrack(board,word,idx+1,x+1,y);         
        if((y > 0 &&!used[x][y-1])&& board[x][y-1] == word[idx+1])             
            backtrack(board,word,idx+1,x,y-1);         
        if((y < m-1 && !used[x][y+1]) && board[x][y+1] == word[idx+1])             
            backtrack(board,word,idx+1,x,y+1);
        used[x][y] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        used.assign(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0])
                    backtrack(board,word,0,i,j);
            }   
        }
        return match;
    }
};