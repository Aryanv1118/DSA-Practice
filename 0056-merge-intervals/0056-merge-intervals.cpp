class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(auto &p : intervals){
            if(ans.size() == 0 || p[0] > ans.back()[1]){
                ans.push_back(p);
            }
            else{
                ans.back()[1] = max(p[1],ans.back()[1]);
            }
        }
        return ans;
    }
};