class Solution {
public:
    int smallestNumber(int n, int t) {
        int x = n;
        while(true){
            int mul = 1;
            n = x;
            while(n){
                mul *= n%10;
                n /= 10;
            }
            if(mul % t == 0)
                break;
            else 
                x++;
        }
        return x;
    }
};