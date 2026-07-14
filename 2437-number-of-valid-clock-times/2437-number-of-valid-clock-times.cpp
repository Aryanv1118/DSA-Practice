class Solution {
public:
    int countTime(string time) {
        int h = 1;
        int mins = 1;
        if(time[0] == '?' && time[1] == '?')
            h = 24; 
        else if(time[0]== '?' && time[1]!='?'){
            if(time[1]-'0' <= 3)
                h = 3;
            else
                h = 2;
        }
        else if(time[0]!='?' && time[1] == '?'){
            if(time[0]-'0'<=1)
                h = 10;
            else
                h = 4;
        }

        if(time[3] == '?' && time[4] == '?')
            mins = 60;
        else if(time[3] == '?' && time[4]!='?'){
            mins = 6;
        }
        else if(time[3]!='?' && time[4] == '?'){
            mins = 10;
        }
        return h*mins;
    }
};