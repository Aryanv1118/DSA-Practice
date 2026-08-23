class Solution {
public:
    bool sumGame(string num) {
        int leftsum = 0;
        int rightsum = 0;
        int n = num.length();
        int q_countl = 0;
        int q_countr = 0; 
        for(int i = 0;i<n/2;i++){
            num[i] == '?' ? q_countl++ : leftsum += num[i]-'0';
            num[n/2+i] == '?' ? q_countr++ : rightsum += num[n/2+i]-'0';
        }
        return ((float)(leftsum - rightsum) != 9*(q_countr-q_countl)/2.0);
    }
};