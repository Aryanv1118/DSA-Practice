class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long sum = 0;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        for(int i = 0;i<k;i++){
            if(mul>k){
                sum += mul*(long long)nums[i];
                mul--;
            }
            else{
                if(mul == 0){
                    sum += nums[i];
                    continue;
                }
                sum += mul*(long long)nums[i];
                mul--;
            }
        }
        return sum;
    }
};