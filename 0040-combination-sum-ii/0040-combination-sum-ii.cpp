class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int idx,vector<int>& curr,int remaining,vector<int>& candidates){
        if(remaining == 0){
            ans.push_back(curr);
            return;
        }
        if(remaining < 0){
            return;
        }
        for(int i = idx;i<candidates.size();i++){
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            curr.push_back(candidates[i]);
            backtrack(i+1,curr,remaining-candidates[i],candidates);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        backtrack(0,curr,target,candidates);
        return ans;
    }
};