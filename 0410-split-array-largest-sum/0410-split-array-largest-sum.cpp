class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        int high = sum;
        int ans;
        while(low<=high){
            int mid = low + (high - low)/2;
            int count = 1;
            int maxsum = 0;
            int temp = 0;
            for(auto num:nums){
                if(temp+num>mid){
                    temp = 0;
                    count++;
                }
                temp += num;
                maxsum = max(maxsum,temp);
            }
            if(count <= k){
                high = mid-1;
                ans = maxsum;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};