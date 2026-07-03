class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int idx,int remaining,vector<int>& curr,vector<int> candidates){
        if(remaining == 0){
            ans.push_back(curr);
            return;
        }
        if(remaining<0){
            return;
        }
        for(int i = idx;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            remaining -= candidates[i];
            backtrack(i,remaining,curr,candidates);
            curr.pop_back();
            remaining += candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(0,target,curr,candidates);
        return ans;
    }
};