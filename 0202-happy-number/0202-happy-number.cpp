class Solution {
public:
    int sosd(int x){
        int sum = 0;
        while(x!=0){
            int digit = x%10;
            sum += digit*digit;
            x = x/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        if(n == 1){
            return true; 
        }
        while(!set.count(n)){
            set.insert(n);
            n = sosd(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
};