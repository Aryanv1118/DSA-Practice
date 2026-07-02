class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int minutes = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int k = q.size();
            bool found = false;
            for(int i = 0;i<k;i++){
                pair<int,int> x = q.front();
                q.pop();
                if(x.first - 1 >= 0 &&  grid[x.first-1][x.second] == 1){
                    fresh--;
                    q.push({x.first-1,x.second});
                    found = true;
                    grid[x.first-1][x.second] = 2;
                }
                if(x.first + 1 < m &&  grid[x.first+1][x.second] == 1){
                    fresh--;
                    q.push({x.first+1,x.second});
                    found = true;
                    grid[x.first+1][x.second] = 2;
                }
                if(x.second - 1 >= 0 &&  grid[x.first][x.second-1] == 1){
                    fresh--;
                    q.push({x.first,x.second-1});
                    found = true;
                    grid[x.first][x.second-1] = 2;
                }
                if(x.second + 1 < n &&  grid[x.first][x.second+1] == 1){
                    fresh--;
                    q.push({x.first,x.second+1});
                    found = true;
                    grid[x.first][x.second+1] = 2;
                }
            }
            if(found){
                minutes++;
            }
        }
        if(fresh == 0)
            return minutes;
        return -1;
    }
};