class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int>free(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq_avail;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq_busy;
        for(int i = 0;i<n;i++){
            pq_avail.push({servers[i],i});
        }
        long long curr = 0;
        vector<int>ans(m);
        for(int i = 0;i<m;i++){
            curr = max(curr,(long long)i);
            while(!pq_busy.empty() && pq_busy.top().first<=curr){
                int idx = pq_busy.top().second;
                pq_busy.pop();
                pq_avail.push({servers[idx],idx});
            }
            while(pq_avail.empty()){
                curr = pq_busy.top().first;
                while(!pq_busy.empty() && pq_busy.top().first<=curr){
                    int idx = pq_busy.top().second;
                    pq_busy.pop();
                    pq_avail.push({servers[idx],idx});
                }
            }
            auto[weight, server] = pq_avail.top();
            pq_avail.pop();
            ans[i] = server;
            pq_busy.push({curr+tasks[i],server});
        }
        return ans;
    }
};