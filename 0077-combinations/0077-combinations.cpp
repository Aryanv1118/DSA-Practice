class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>&curr,int idx,int n,int k){
        if(curr.size() == k){
            ans.push_back(curr);
            return;
        }
        for(int i = idx;i<=n;i++){
            curr.push_back(i);
            backtrack(curr,i+1,n,k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(curr,1,n,k);
        return ans;
    }
};