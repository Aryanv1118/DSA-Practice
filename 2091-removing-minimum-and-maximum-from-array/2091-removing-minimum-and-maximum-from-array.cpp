class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = min_element(nums.begin(),nums.end()) - nums.begin();
        int mx = max_element(nums.begin(),nums.end()) - nums.begin();
        int a,b;
        a = max(mn,mx);
        b = min(mn,mx);
        return min({n-a+b+1,a+1,n-b});
    }
};