class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        if(target > nums[high-1]){
            return high;        
        }
        if(target < nums[low])
            return 0; 
        while(low<high){
            int mid = low + (high - low)/2;
            if(target <= nums[mid]){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};