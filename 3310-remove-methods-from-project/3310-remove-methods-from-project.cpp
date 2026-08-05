class Solution {
public:
    vector<bool>bug;
    void dfs(int k,vector<vector<int>>&nums){
        bug[k] = true;
        for(int x:nums[k]){
            if(!bug[x]){
                dfs(x,nums);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        bool match = true;
        bug.assign(n,false);
        vector<int>ans;
        vector<vector<int>>adj(n);
        for(auto &x:invocations){
            adj[x[0]].push_back(x[1]);
        }
        dfs(k,adj);
        for(auto &x:invocations){
            if(!bug[x[0]] && bug[x[1]])
                match = false;
        }
        if(match){
            for(int i = 0;i<n;i++){
                if(!bug[i])
                    ans.push_back(i);
            }
        }
        else{
            for(int i = 0;i<n;i++)
                ans.push_back(i);
        }
        return ans;
    }
};