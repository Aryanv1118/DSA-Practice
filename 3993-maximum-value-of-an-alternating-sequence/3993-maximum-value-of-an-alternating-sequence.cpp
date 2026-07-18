class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long up1 = n / 2;
        long long ans1 = s + up1 * 1LL * m - max(0LL, up1 - 1);

        long long up2 = (n - 1LL) / 2;
        long long ans2 = max(1LL * s, 1LL * s + up2 * 1LL * (m - 1));

    return max(ans1, ans2);
}
};