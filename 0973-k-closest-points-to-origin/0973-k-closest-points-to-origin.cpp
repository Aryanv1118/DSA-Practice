class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        vector<vector<int>> ans;
        for(vector<int> x : points){
            int curr_dist = x[0]*x[0]+x[1]*x[1];
            if(pq.size()<k){
                pq.push({curr_dist,x});
            }
            else{
                int prev_dist = pq.top().first;
                if(prev_dist>curr_dist){
                    pq.pop();
                    pq.push({curr_dist,x});
                }
                else{
                    continue;
                }
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};