class Solution {
public:
    long long countCommas(long long n) {
        return n<=999?0:n-999+max(n-999999,1LL*0)+max(n-999999999,1LL*0)+max(n-999999999999,1LL*0)+max(n-999999999999999,1LL*0);
    }
};