class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int prefix = 0;
        mp[0] = -1;
        int maxlen = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                prefix--;
            }
            else{
                prefix++;
            }
            if(mp.count(prefix)){
                maxlen = max(maxlen,i-mp[prefix]);
            }
            else{
                mp[prefix] = i;
            }
        }
        return maxlen;
    }
};