class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        unordered_map<long long,long long> buckets;
        for(int i = 0;i<n;i++){
            int bucket = nums[i]/((long long)valueDiff+1);
            if(nums[i]<0)
                bucket = (nums[i]-1)/((long long)valueDiff+1)-1;
            if(buckets.find(bucket)!=buckets.end())
                return true;
            else{
                buckets[bucket] = nums[i];
                if(buckets.find(bucket-1)!=buckets.end() && llabs((long long)buckets[bucket-1]-nums[i])<=valueDiff)
                    return true;
                if(buckets.find(bucket+1)!=buckets.end() && llabs((long long)buckets[bucket+1]-nums[i])<=valueDiff)
                    return true;
                if(buckets.size()>indexDiff){
                    int remove = nums[i-indexDiff]/((long long)valueDiff+1);
                    if(nums[i-indexDiff]<0){
                        remove = (nums[i-indexDiff]-1)/((long long)valueDiff+1)-1;
                    }
                    buckets.erase(remove);
                }
            }
            
        }
        return false;
    }
};