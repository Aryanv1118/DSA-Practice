class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>vis(n,false);
        pq.push({0,0});
        int total = 0;
        int connected=0;
        while(!pq.empty() && connected<n){
            auto[dist,node] = pq.top();
            pq.pop();
            if(vis[node])continue;
            vis[node] = true;
            total += dist;
            connected++;
            for(int v = 0;v<n;v++){
                if(!vis[v]){
                    int d = abs(points[node][0]-points[v][0]) + abs(points[node][1]-points[v][1]);
                    pq.push({d,v}); 
                }
            }
        }
        return total;
    }
};