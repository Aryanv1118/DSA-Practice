class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(),coins.end());
        vector<int>filter;
        for(int coin:coins){
            bool redundant = false;
            for(int f:filter){
                if(coin%f == 0){
                    redundant = true;
                    break;
                }
            }
            if(!redundant) filter.push_back(coin);
        }
        int n = filter.size();
        auto count = [&](long long target){
            long long total = 0;
            for(int mask = 1;mask<(1<<n);mask++){
                long long curr_lcm = 1;
                int set_bits = 0;
                for(int j = 0;j<n;j++){
                    if((mask>>j) & 1){
                        set_bits++;
                        curr_lcm = lcm(curr_lcm,(long long)filter[j]);
                    }
                }
                if(set_bits%2 != 0)
                    total += target/curr_lcm;
                else
                    total -= target/curr_lcm;
            }
            return total;
        };
        long long low = 1;
        long long high = 1LL*filter[0]*k;
        long long ans = high;
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(count(mid)>=k){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans; 
    }
};