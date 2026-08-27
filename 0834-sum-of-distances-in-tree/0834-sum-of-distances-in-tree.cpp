class Solution {
public:
    vector<int>subTree;
    vector<int>ans;
    void dfs2(int child,int parent,vector<vector<int>>&adjList,int n){
        for(int v:adjList[child]){
            if(v == parent)continue;
            ans[v] = ans[child] + n - 2*subTree[v];
            dfs2(v,child,adjList,n);
        }
    }
    int dfs1(int child,int parent,vector<vector<int>>&nums){
        subTree[child] = 1;
        for(int v:nums[child]){
            if(v == parent){
                continue;
            }
            subTree[child] += dfs1(v,child,nums);
        }
        return subTree[child];
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        subTree.assign(n,0);
        ans.assign(n,0);
        vector<vector<int>>adjList(n);
        for(auto &edge:edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        dfs1(0,-1,adjList);
        for(int i = 1;i<n;i++){
            ans[0] += subTree[i];
        }
        dfs2(0,-1,adjList,n);
        return ans;
    }
};