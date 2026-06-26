class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int i = nums.size()-k;
        for(int x : nums){
            if(pq.size()<k){
                pq.push(x);
            }
            else{
                if(x > pq.top()){
                    pq.pop();
                    pq.push(x);
                }
                else{
                    continue;
                }
            }
            i++;
        }
        return pq.top();
    }
};