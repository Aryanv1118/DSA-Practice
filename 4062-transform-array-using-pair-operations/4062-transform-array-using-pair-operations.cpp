class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        if(source.size() == 1)
            return source[0] == target[0];
        long long sum1 = 0;
        long long sum2 = 0;
        for(int i = 0;i<source.size();i++){
            sum1 += source[i];
            sum2 += target[i];
        }
        return sum1 == sum2;
    }
};