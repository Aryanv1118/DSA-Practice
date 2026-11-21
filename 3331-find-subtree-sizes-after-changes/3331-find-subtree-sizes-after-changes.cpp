class Solution {
public:
    vector<vector<int>>adj,tree;
    vector<int>last,ans;
    string str;
    void dfs1(int u,vector<int>&parent){
        int c = str[u]-'a';
        int prev = last[c];
        last[c] = u;
        for(int v:adj[u]){
            int p = last[str[v]-'a'];
            if(p == -1)
                p = parent[v];
            tree[p].push_back(v);
            dfs1(v,parent);
        }
        last[c] = prev;
    }
    void dfs2(int u){
        for(int v:tree[u]){
            dfs2(v);
            ans[u] += ans[v];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.length();
        str = s;
        adj.assign(n,{});
        tree.assign(n,{});
        last.assign(26,-1);
        ans.assign(n,1);
        for(int i = 1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs1(0,parent);
        dfs2(0);
        return ans;
    }
};