class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq;
        int ans = 0;
        for(auto x:nums) 
            freq[x]++;
        if(freq[1]%2 == 0)
            ans = freq[1]-1;
        else
            ans = freq[1];
        freq.erase(1);
        for(auto p:nums){
            int len = 0;
            long long num = p;
            for(;freq.contains(num) && freq[num]>1;num *= num)
                len += 2;
            ans = max(ans,freq[num] ? len+1:len-1);
        }
        return ans;
    }
};