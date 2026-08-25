class Solution {
public:
    vector<vector<bool>>vis;
    void dfs(vector<vector<int>>&grid,int sr,int sc,int color,int check){
        if(sr>=grid.size() || sr < 0 || sc >= grid[0].size() || sc < 0 || grid[sr][sc]!=check || vis[sr][sc]){
            return;
        }
        vis[sr][sc] = true;
        if(grid[sr][sc] == check)
            grid[sr][sc] = color;
        dfs(grid,sr+1,sc,color,check);
        dfs(grid,sr-1,sc,color,check);
        dfs(grid,sr,sc+1,color,check);
        dfs(grid,sr,sc-1,color,check);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int m = image.size();
        int n = image[0].size();
        vis.assign(m,vector<bool>(n,false));
        int check = image[sr][sc];
        dfs(ans,sr,sc,color,check);
        return ans;  
    }
};