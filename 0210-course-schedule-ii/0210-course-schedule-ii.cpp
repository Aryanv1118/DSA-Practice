class Solution {
public:
    bool dfs(int start,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
        vis[start] = 1;
        for(int k:adj[start]){
            if(vis[k] == 1){
                return true;
            }
            if(vis[k] == 0){
                if(dfs(k,vis,adj,st)){
                    return true;
                }
            }
        }
        vis[start] = 2;
        st.push(start);
        return false;   
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>vis(numCourses,0);
        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        stack<int>st;
        for(int i = 0;i<numCourses;i++){
            if(vis[i] == 0){
                if(dfs(i,vis,adj,st))return {};
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};