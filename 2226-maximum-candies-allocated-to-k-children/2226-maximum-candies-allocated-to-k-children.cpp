class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = 0;
        for(int x:candies){
            sum += x;
        }
        if(sum<k){
            return 0;
        }
        int low = 1;
        int high = *max_element(candies.begin(),candies.end());
        int ans = 0;
        int min_ele = *min_element(candies.begin(),candies.end());
        while(low<=high){
            int mid = low+(high - low)/2;
            long long piles = 0;
            for(auto x:candies){
                piles += x/mid;
            }
            if(piles >= k){
                low = mid+1;
                ans = mid;
            }
            else if(piles < k){
                high = mid-1;
            }
        }
        return ans;
    }
};