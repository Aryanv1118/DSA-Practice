class Solution {
public:
    int maxDistance(string moves) {
        int x_end = 0;
        int y_end = 0;
        int count = 0; 
        int n = moves.size();
        for(int i = 0;i<n;i++){
            if(moves[i] == 'L'){
                x_end--;
            }
            else if(moves[i] == 'R'){
                x_end++;
            }
            else if(moves[i] == 'U'){
                y_end++;
            }
            else if(moves[i] == 'D'){
                y_end--;
            }
            else{
                count++;
            }
        }
        int x_sign = 1;
        int y_sign = 1; 
        if(x_end != 0)
            x_sign = x_end/abs(x_end);
        if(y_end !=0 )
            y_sign = y_end/abs(y_end);
            
        int ans = 0;
        for(int i = 0;i<=count;i++){
            ans = max(ans,abs(x_end+x_sign*(count-i)-0)+abs(y_end+(y_sign*i)-0));
        }
        return ans;
    }
};