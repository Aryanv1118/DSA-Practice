class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        k = k%(m*n);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int idx = n*i+j+k;
                int col = idx%n;
                int row = (idx/n)%m;
                ans[row][col] = grid[i][j];
            }
        }
        return ans;
    }
};