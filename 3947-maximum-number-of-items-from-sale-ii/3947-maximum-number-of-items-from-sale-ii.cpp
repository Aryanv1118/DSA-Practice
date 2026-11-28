class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int maxF = 0;
        long long minprice = LLONG_MAX;
        for(auto item:items){
            maxF = max(maxF,item[0]);
            minprice = min(minprice,(long long)item[1]);
        }
        vector<int>divcount(maxF+1,0);
        vector<int>freq(maxF+1,0);
        for(auto item:items){
            freq[item[0]]++;
        }
        for(int f = 1;f<=maxF;f++){
            for(int mult = f;mult<=maxF;mult += f){
                divcount[f] += freq[mult];
            }
        }
        vector<pair<long long,long long>>pool;
        for(auto item:items){
            int f = item[0];
            int p = item[1];
            int rem = divcount[f]-1;
            if(rem>0 && p<2*minprice){
                pool.push_back({p,rem});
            }
        }
        sort(pool.begin(),pool.end());
        long long rembudget = budget;
        long long lastprice = -1;
        long long totalitems = 0;
        for(auto [p,cnt]:pool){
            long long canbuy = min(cnt,rembudget/p);
            if(canbuy > 0){
                rembudget -= canbuy*p;
                totalitems += canbuy*2;
                lastprice = p;
            }
            if(canbuy<cnt)break;
        }
        long long ans = totalitems + (rembudget/minprice);
        if(lastprice!=-1){
            long long altbudget = rembudget+lastprice;
            long long altitem = totalitems-2+altbudget/minprice;
            ans = max(ans,altitem);
        }
        return ans;
    }
};