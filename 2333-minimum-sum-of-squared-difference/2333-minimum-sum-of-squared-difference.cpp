class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        int k = k1+k2;
        vector<int>diff(n);
        for(int i = 0;i<n;i++){
            diff[i] = abs(nums1[i]-nums2[i]);
        }
        sort(diff.rbegin(),diff.rend());
        unordered_map<int,int>mp;
        for(int x:diff){
            if(x>0)mp[x]++;
        }
        if(mp.empty() || k == 0){
            long long sum = 0;
            for(auto[dif,count]:mp) sum += count*(long long)dif*dif;
            return sum;
        }
        vector<pair<long long,long long>>freq;
        freq.push_back({0,0});
        long long cnt = 0;
        for(auto&it:mp){
            freq.push_back({it.first,it.second});
        }
        sort(freq.begin(), freq.end(), [](const pair<long long, long long>& a, const pair<long long, long long>& b) {
            return a.first > b.first;
        });
        int count = 0;
        for(int i = 0;i<freq.size()-1;i++){
            long long td = freq[i].first-freq[i+1].first;
            count += freq[i].second;
            long long need = count*td;
            if(k>=need){
                k -= need;
            }
            else{
                long long dall = k/count;
                long long rem = k%count;
                long long base = freq[i].first-dall;
                long long ans = rem*(base-1)*(base-1)+(count-rem)*base*base;
                for(int j = i+1;j<freq.size();j++){
                    ans += (freq[j].first*freq[j].first*freq[j].second);
                }
                return ans;
            }
        }
        return 0;
    }
};