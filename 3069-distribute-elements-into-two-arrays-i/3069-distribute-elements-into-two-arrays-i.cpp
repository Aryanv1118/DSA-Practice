class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v1;
        vector<int>v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        for(int i = 2;i<n;i++){
            v1.back() > v2.back() ? v1.push_back(nums[i]) : v2.push_back(nums[i]);
        }
        v1.reserve(v1.size()+v2.size());
        v1.insert(v1.end(),v2.begin(),v2.end());
        return v1;    
    }
};