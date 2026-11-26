class Solution {
public:
    bool canAliceWin(int n) {
        int ans = false;
        for(int i = 10;i>=1;i--){
            if(n<i&&i%2 == 0){
                ans = false;
                break;
            }
            else if(n<i && i%2){
                ans = true;
                break;
            }
            n -= i;
        }
        return ans;
    }
};