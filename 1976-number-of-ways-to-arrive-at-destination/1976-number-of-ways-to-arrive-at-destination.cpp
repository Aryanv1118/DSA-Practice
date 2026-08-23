class Solution {
public:
    static const int mod = 1000000007;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adjList(n);
        for(vector<int> &a:roads){
            adjList[a[0]].push_back({a[1],a[2]});
            adjList[a[1]].push_back({a[0],a[2]});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto[time,node] = pq.top();
            pq.pop();
            if(time > dist[node])
                continue;
            for(auto[next,weight] : adjList[node]){
                long long newtime = time + weight;
                if(newtime < dist[next]){
                    dist[next] = newtime;
                    ways[next] = ways[node];
                    pq.push({newtime,next});
                }
                else if(newtime == dist[next]){
                    ways[next] = (ways[next]+ways[node])%mod;
                }
            }
        } 
        return ways[n-1];
    }
};