class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] != 0){
                    long long count = 0;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    count += grid[i][j];
                    grid[i][j] = 0;
                    while(!q.empty()){
                        int a = q.front().first;
                        int b = q.front().second;
                        q.pop();
                        if(a>0 && b>= 0 && a<n && b<m && grid[a-1][b]!=0){
                            count += grid[a-1][b];
                            q.push({a-1,b});
                            grid[a-1][b] = 0;
                        }
                        if(a>=0 && b>= 0 && a<n-1 && b<m && grid[a+1][b]!=0){
                            count += grid[a+1][b];
                            q.push({a+1,b});
                            grid[a+1][b] = 0;
                        }
                        if(a>=0 && b> 0 && a<n && b<m && grid[a][b-1]!=0){
                            count += grid[a][b-1];
                            q.push({a,b-1});
                            grid[a][b-1] = 0;
                        }
                        if(a>=0 && b>= 0 && a<n && b<m-1 && grid[a][b+1]!=0){
                            count += grid[a][b+1];
                            q.push({a,b+1});
                            grid[a][b+1] = 0;
                        }
                    }
                    if(count%k == 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};