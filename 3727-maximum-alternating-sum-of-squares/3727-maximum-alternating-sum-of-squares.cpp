class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>temp = nums;
        sort(temp.begin(),temp.end(),[](int &a,int &b){
            return abs(a)<abs(b);
        });
        int i = 0;
        int j = nums.size()-1;
        long long ans = 0;
        while(i<=j){
            if(i == j){
                ans += temp[i]*temp[i];
                break;
            }
            ans += temp[j]*temp[j];
            ans -= temp[i]*temp[i];
            i++;
            j--;
        }
        return ans;
    }
};