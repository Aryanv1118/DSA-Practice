class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int idx,vector<vector<int>>&graph,vector<int>&current){
        current.push_back(idx);
        if(idx == graph.size()-1){
            ans.push_back(current);
        }
        else{
            for(int x:graph[idx]){
                dfs(x,graph,current);
            }
        }
        current.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        dfs(0,graph,temp);
        return ans;
    }
};