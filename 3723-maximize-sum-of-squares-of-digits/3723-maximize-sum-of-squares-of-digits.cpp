class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(sum!=0 && num!= 0){
            if(9<=sum){
                ans.push_back('9');
                sum -= 9;
                num--;
            }
            else if(sum>0 && sum<9){
                ans.push_back(sum+'0');
                sum = 0;
                num--;
            }
        }
        if(num == 0 && sum>0)return "";
        if(sum==0 && num>0){
            ans+= string(num,'0');
        }
        return ans;
    }
};