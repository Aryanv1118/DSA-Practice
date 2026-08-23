class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>time(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adjList(n+1);
        for(vector<int>&a:times){
            adjList[a[0]].push_back({a[1],a[2]});
        }
        time[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto[d,u] = pq.top();
            pq.pop();
            if(d>time[u])continue;
            for(auto& [node,dist]: adjList[u]){
                if(d+dist<time[node]){
                    time[node] = d+dist;
                    pq.push({time[node],node});
                }
            }
        }
        int max_ele = *max_element(time.begin()+1,time.end());
        return (max_ele == INT_MAX) ? -1 : max_ele;
    }
};