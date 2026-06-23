class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand;
        int count = 0;
        for(int x:nums){
            if(x == cand)
                count++;
            else if(count == 0)
                cand = x;
            else{
                count--;
            }
        }
        return cand;
    }
};