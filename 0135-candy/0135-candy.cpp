class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum = 0;
        int n = ratings.size();
        int up = 0;
        int down = 0;
        int i = 0;
        int prev = 0;
        int curr = 0;
        while(i<n-1){
            curr = (ratings[i+1] > ratings[i]) ? 1 : (ratings[i+1]<ratings[i]) ? -1:0;
            if(prev > 0 && curr == 0 || prev<0 && curr >= 0){
                sum += up*(up+1)/2 + down*(down+1)/2 + max(up,down);
                up = 0;
                down = 0;
            }
            if(ratings[i]>ratings[i+1])down++;
            else if(ratings[i]<ratings[i+1])up++;
            else sum++;
            prev = curr;
            i++;
        }
        sum += up*(up+1)/2 + down*(down+1)/2 + max(up,down)+1;
        return sum;
    }
};