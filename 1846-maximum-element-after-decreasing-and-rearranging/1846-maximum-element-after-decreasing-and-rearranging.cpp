class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int diff = 0;
        sort(arr.begin(),arr.end());
        int ans = 1;
        for(int i = 1;i<n;i++){
            diff = arr[i]-ans;
            if(diff >= 1){
                ans++;
            }
        }
        return ans;
    }
};