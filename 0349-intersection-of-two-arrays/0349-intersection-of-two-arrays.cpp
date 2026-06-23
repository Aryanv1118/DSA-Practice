class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> tmp;
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0;i<n1;i++){
            tmp.insert(nums1[i]);
        }
        for(int i = 0;i<n2;i++){
            if(tmp.count(nums2[i])){
                ans.push_back(nums2[i]);
                tmp.erase(nums2[i]);
            }
        }
        return ans;
    }
};