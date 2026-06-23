class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int maxlen = 0;
        for(int n:set){
            if(!set.count(n-1)){
                int curr = n;
                int len = 1;
                while(set.count(curr+1)){
                    curr++;
                    len++;
                }
                maxlen = max(maxlen,len);
            }
        }
        return maxlen;
    }
};