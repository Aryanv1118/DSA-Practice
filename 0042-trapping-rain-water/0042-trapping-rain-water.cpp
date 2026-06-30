class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftmax = -1;
        int rightmax = -1;
        int ans = 0;
        while(left<right){
            leftmax = max(leftmax,height[left]);
            rightmax = max(rightmax,height[right]);
            if(leftmax<rightmax){
                ans += leftmax - height[left];
                left++;
            }
            if(rightmax<=leftmax){
                ans += rightmax - height[right];
                right--;
            }
        }
        return ans;
    }
};