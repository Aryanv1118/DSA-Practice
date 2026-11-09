class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int>req(k,0);
        set<int>avail;
        for(int i = 0;i<k;i++){
            avail.insert(i);
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq_busy;
        long long curr = 0;
        for(int i = 0;i<n;i++){
            long long time = arrival[i];
            long long dur = load[i];
            while(!pq_busy.empty() && pq_busy.top().first<=time){
                int idx = pq_busy.top().second;
                avail.insert(idx);
                pq_busy.pop();
            }
            if(avail.empty())continue;
            auto it = avail.lower_bound(i%k);
            if(it == avail.end()){
                it = avail.begin();
            }
            int server = *it;
            req[server]++;
            pq_busy.push({time+dur,server});
            avail.erase(it);
        }
        int mx = *max_element(req.begin(),req.end());
        vector<int>ans;
        for(int i = 0;i<k;i++){
            if(req[i] == mx){
                ans.push_back(i);
            }
        }
        return ans;
    }
};