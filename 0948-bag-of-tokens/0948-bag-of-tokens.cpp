class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 0;
        int j = n-1;
        int points = 0;
        int maxpoints = 0;
        int avl = power;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            if(avl >= tokens[i]){
                avl -= tokens[i];
                points += 1;
                i++;
            }
            else if(points > 0 && avl < tokens[i]){
                points -= 1;
                avl += tokens[j];
                j--;
            }
            maxpoints = max(maxpoints,points);
            if(points == 0 && tokens[i] > avl)
                break;
            
        }
        return maxpoints;
    }
};