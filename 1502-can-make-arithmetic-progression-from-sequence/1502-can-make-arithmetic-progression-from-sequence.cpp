class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int cd = abs(arr[1]-arr[0]);
        for(int i = 0;i<n-1;i++){
            if(abs(arr[i+1]-arr[i]) != cd)return false;
        }
        return true;
    }
};