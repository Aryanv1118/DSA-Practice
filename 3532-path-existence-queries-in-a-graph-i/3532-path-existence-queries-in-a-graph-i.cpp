class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> graph(n,0);
        int curr = 0;
        graph[0] = 0;
        for(int i = 1;i<n;i++){
            if(nums[i]-nums[i-1] > maxDiff)
                curr++;
            graph[i] = curr;
        }
        vector<bool> ans;
        for(vector<int> query: queries){
            if(graph[query[0]] == graph[query[1]])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;   
    }
};