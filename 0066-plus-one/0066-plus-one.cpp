class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>nums(digits.begin(),digits.end());
        if(nums[n-1]!=9){
            nums[n-1]++;
            return nums;
        }
        else{
            int i = n-1;
            while(i >=0 && nums[i] == 9){
                nums[i] = 0;
                i--;
            }
            if(i!=-1){
                nums[i]++;
            }
            else{
                nums.assign(n+1,0);
                nums[0] = 1;
            }
        }
        return nums;
    }
};