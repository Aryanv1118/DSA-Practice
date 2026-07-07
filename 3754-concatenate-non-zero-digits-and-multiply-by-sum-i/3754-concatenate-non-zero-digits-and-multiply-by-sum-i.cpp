class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string s;
        int temp = n;
        if(n == 0)
            return 0;
        while(temp>0){
            int digit = temp%10;
            if(digit!=0){
                s += '0'+digit;
            }
            sum += digit;
            temp = temp/10;
        }
        reverse(s.begin(),s.end());
        long long x = stoll(s);
        long long ans = x*sum;
        return ans; 
    }
};