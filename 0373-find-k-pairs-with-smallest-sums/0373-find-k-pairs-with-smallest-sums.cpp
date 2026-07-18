class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using p = pair<int,pair<int,int>>;
        priority_queue<p,vector<p>,greater<p>>pq;
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>ans;
        if(m == 0 || n == 0 || k == 0){
            return ans;
        }
        for(int i = 0;i<n;i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        while(k-- && !pq.empty()){
            auto [sum,indices] = pq.top();
            pq.pop();
            int i = indices.first;
            int j = indices.second;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<m){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
        }
        return ans;
    }
};