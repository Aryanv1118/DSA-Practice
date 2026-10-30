class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
        }
        vector<vector<int>>dist(n,vector<int>(k+1,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        dist[0][1] = 0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto[cost,u,cnt] = pq.top();
            pq.pop();
            if(cost!=dist[u][cnt])
                continue;
            if(u == n-1)
                return cost;
            for(auto[v,wt]:adj[u]){
                int newCnt;
                if(labels[u] == labels[v]){
                    newCnt = cnt+1;
                }
                else{
                    newCnt = 1;
                }
                if(newCnt>k){
                    continue;
                }
                int newcost = cost+wt;
                if(newcost<dist[v][newCnt]){
                    dist[v][newCnt] = newcost;
                    pq.push({newcost,v,newCnt});
                }
            }
        }
        return -1;
    }
};