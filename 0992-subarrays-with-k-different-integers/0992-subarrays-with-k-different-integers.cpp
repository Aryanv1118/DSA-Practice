class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int,int> mp;
        int count1 = 0;
        int count2 = 0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            count1 += r-l+1;;
            r++;
        }
        l = 0;
        r = 0;
        mp.clear();
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k-1){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            count2 += r-l+1;
            r++;
        }
        return count1-count2;
    }
};