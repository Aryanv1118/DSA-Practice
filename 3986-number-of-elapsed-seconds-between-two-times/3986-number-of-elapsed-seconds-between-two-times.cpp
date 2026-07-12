class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int secs = 0;
        int start = (startTime[0]-'0')*10*60*60+(startTime[1]-'0')*60*60+(startTime[3]-'0')*10*60+(startTime[4]-'0')*60+(startTime[6]-'0')*10+(startTime[7]-'0');
        int end = (endTime[0]-'0')*10*60*60+(endTime[1]-'0')*60*60+(endTime[3]-'0')*10*60+(endTime[4]-'0')*60+(endTime[6]-'0')*10+(endTime[7]-'0');
        return end-start;
    }
};