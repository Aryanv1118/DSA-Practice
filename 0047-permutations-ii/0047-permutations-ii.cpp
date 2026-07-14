class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>> set;
    void backtrack(vector<int>& curr,vector<bool>& pos,vector<int>& nums){
        if(curr.size() == nums.size()){
            set.insert(curr);
        }
        for(int i =0;i<nums.size();i++){
            if(pos[i])
                continue;
            curr.push_back(nums[i]);
            pos[i] = true;
            backtrack(curr,pos,nums);
            curr.pop_back();
            pos[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> pos(nums.size(),false);
        vector<int> curr;
        backtrack(curr,pos,nums);
        for(auto x:set){
            ans.push_back(x);
            set.erase(x);
        }
        return ans;
    }
};