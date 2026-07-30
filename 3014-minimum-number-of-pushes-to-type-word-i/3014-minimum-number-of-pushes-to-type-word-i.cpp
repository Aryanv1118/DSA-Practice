class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int m = n/8;
        int t = n%8;
        int sum = (m*(m+1))/2;
        return (m+1)*t+sum*8;
    }
};