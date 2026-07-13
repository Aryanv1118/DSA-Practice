class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int n = weights.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += weights[i];
        }
        int high = sum; 
        int ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            int d = 1;
            int temp = 0;
            for(int w:weights){
                if(temp+w>mid){
                    temp = 0;
                    d++;
                }
                temp += w;
            }
            if(d <= days){
                high = mid-1;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};