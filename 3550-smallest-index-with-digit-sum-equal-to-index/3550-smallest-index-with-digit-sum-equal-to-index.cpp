class Solution {
public:
    int digSum(int x){
        int sum = 0;
        while(x!=0){
            int digit = x%10;
            sum += digit;
            x /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i == digSum(nums[i])){
                ans = i;
                break;
            }
        }
        return ans;
    }
};