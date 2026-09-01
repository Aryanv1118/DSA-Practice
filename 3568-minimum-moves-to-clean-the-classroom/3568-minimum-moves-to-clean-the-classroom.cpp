class Solution {
public:
    struct State {
        int r, c, energy, mask;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc, cnt = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if(classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int full = (1 << cnt) - 1;

        queue<State> q;
        q.push({sr, sc, energy, 0});

        vector<vector<vector<vector<bool>>>>vis(m,vector<vector<vector<bool>>>(n,vector<vector<bool>>(energy + 1,vector<bool>(1 << cnt, false))));
        vis[sr][sc][energy][0] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int dist = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                State cur = q.front();
                q.pop();
                if(cur.mask == full)
                    return dist;
                for(int d = 0; d < 4; d++) {
                    int nr = cur.r + dr[d];
                    int nc = cur.c + dc[d];
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    if(classroom[nr][nc] == 'X')
                        continue;
                    if(cur.energy == 0)
                        continue;
                    int ne = cur.energy - 1;
                    int nmask = cur.mask;
                    if(classroom[nr][nc] == 'R')
                        ne = energy;
                    if(classroom[nr][nc] == 'L') {
                        nmask |= (1 << id[nr][nc]);
                    }
                    if(!vis[nr][nc][ne][nmask]) {
                        vis[nr][nc][ne][nmask] = true;
                        q.push({nr, nc, ne, nmask});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};