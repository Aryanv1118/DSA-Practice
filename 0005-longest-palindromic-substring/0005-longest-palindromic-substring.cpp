class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<int> d1(n);
        int l = 0;
        int r = -1;
        int ans = 0;
        int left = 0;
        int right = 0;
        for(int i = 0;i<n;i++){
            int k = (i>r)?1:min(d1[l+r-i],r-i+1);
            while(i-k>=0 && i+k < n && s[i-k] == s[i+k]){
                k++;
            }
            d1[i] = k;
            if(2*k-1>ans){
                left = i-k+1;
                right = i+k-1;
                ans = 2*k-1;
            }
            if(i+k-1>r){
                l = i-k+1;
                r = i+k-1;
            }
        }
        vector<int>d2(n);
        l = 0;
        r = -1;
        for(int i = 0;i<n;i++){
            int k  = (i>r)?0:min(d2[l+r-i+1],r-i+1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k])
                k++;
            d2[i] = k;
            if(2*k>ans){
                left = i-k;
                right = i+k-1;
                ans = 2*k;
            }
            if(i+k-1>r){
                l = i-k;
                r = i+k-1;
            }
        }
        string answer(s.begin()+left,s.begin()+right+1);
        return answer;
    }
};