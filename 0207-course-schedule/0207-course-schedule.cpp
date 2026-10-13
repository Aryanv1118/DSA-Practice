class Solution {
public:
    bool isCycle(int start,vector<bool>&vis,vector<bool>&used,vector<vector<int>>&edge){
        vis[start] = true;
        used[start] = true;
        for(int i = 0;i<edge.size();i++){
            int v = edge[i][0];
            int u = edge[i][1];
            if(u == start){
                if(!vis[v]){
                    if(isCycle(v,vis,used,edge)){
                        return true;
                    }
                }
                else if(used[v]){
                    return true;
                }
            }
        }
        used[start] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>used(numCourses,false);
        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i,vis,used,prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};