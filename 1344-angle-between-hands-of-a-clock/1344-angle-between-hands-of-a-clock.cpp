class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mha = 6*minutes;
        double hha = (hour*60 + minutes)*0.5;
        double diff = abs(hha-mha);
        return min(diff,360-diff); 
    }
};