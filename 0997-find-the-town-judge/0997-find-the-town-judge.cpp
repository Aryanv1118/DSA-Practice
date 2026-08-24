class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adjList(n+1);
        vector<int>trustee(n+1,0);
        for(auto edge:trust){
            adjList[edge[0]].push_back(edge[1]);
            trustee[edge[1]]++;
        }
        int ans = -1;
        for(int i = 1;i<=n;i++){
            if(adjList[i].empty() && trustee[i] == n-1){
                ans = i;
            }
        }
        return ans;
    }
};