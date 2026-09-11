class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int total = 1;
        int current = 9;
        for(int i = 1;i<=n;i++){
            if(i == 1){
                total += 9;
            }
            else{
                current *= 11-i;
                total += current;
            }
        }
        return total;
    }
};