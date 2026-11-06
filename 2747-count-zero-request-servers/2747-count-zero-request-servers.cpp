class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int qn = queries.size();
        sort(logs.begin(),logs.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        vector<int>freq(n+1,0);
        vector<pair<int,int>>sorted;
        vector<int>ans(qn);
        for(int q = 0;q<qn;q++){
            sorted.push_back({queries[q],q});
        }
        sort(sorted.begin(),sorted.end());
        int l = 0;
        int r = 0;
        int uniq = 0;
        for(int i = 0;i<qn;i++){
            int t = sorted[i].first;
            int idx = sorted[i].second;
            int start = t-x;
            while(r<logs.size() && logs[r][1]<=t){
                int id = logs[r][0];
                if(freq[id] == 0)
                    uniq++;
                freq[id]++;
                r++;
            }
            while(l<logs.size() && logs[l][1]<start){
                int id = logs[l][0];
                freq[id]--;
                if(freq[id] == 0)
                    uniq--;
                l++;
            }
            ans[idx] = n-uniq;
        }
        return ans;
    }
};