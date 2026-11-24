class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        for(int i = 0;i<n;i++){
            long long prod = 1;
            long long l_c_m = nums[i];
            long long g_c_d = nums[i];
            for(int j = i;j<n;j++){
                prod *= (long long)nums[j];
                if(prod>25200)break;
                l_c_m = lcm(l_c_m,(long long)nums[j]);
                g_c_d = gcd(g_c_d,(long long)nums[j]);
                if(prod == l_c_m*g_c_d){
                    len = max(j-i+1,len);
                }
            }
        }
        return len;
    }
};