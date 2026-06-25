class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int d5 = 0;
        int d10 = 0;
        int d20 = 0;
        int n = bills.size();
        for(int i = 0;i<n;i++){
            if(bills[i] == 5){
                d5++;
            }
            else if(bills[i] == 10){
                d10++;
                d5--;
            }
            else{
                if(d10>0&&d5>0){
                    d10--;
                    d5--;
                }
                else{
                    d5 = d5 - 3;
                }
            }
            if(d5<0||d10<0||d20<0){
                return false;
            }
        }
        return true;
    }
};