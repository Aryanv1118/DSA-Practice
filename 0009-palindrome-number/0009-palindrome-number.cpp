class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0){
            return true;
        }
        if(x < 0){
            return false;
        }
        int org = x;
        int rev = 0;
        while(x!=0){
            int digits = x%10;
            if(rev > INT_MAX /10 || rev < INT_MIN /10){
                return 0;
            }
            rev = rev*10+digits;
            x = x/10;
        }
        if(org == rev){
            return true;
        }
        else{
            return false;
        }
    }
};