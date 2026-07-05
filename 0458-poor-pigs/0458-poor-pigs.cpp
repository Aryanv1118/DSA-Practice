class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int rounds = (minutesToTest/minutesToDie)+1;
        while(pow(rounds,pigs)<buckets){
            pigs++;
        }
        return pigs;
    }
};