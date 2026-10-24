class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>days = {0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int alice_start = days[(arriveAlice[0]-'0')*10+(arriveAlice[1]-'0')-1]+(arriveAlice[3]-'0')*10+(arriveAlice[4]-'0');
        int alice_end = days[(leaveAlice[0]-'0')*10+(leaveAlice[1]-'0')-1]+(leaveAlice[3]-'0')*10+(leaveAlice[4]-'0');
        int Bob_start = days[(arriveBob[0]-'0')*10+(arriveBob[1]-'0')-1]+(arriveBob[3]-'0')*10+(arriveBob[4]-'0');
        int Bob_end = days[(leaveBob[0]-'0')*10+(leaveBob[1]-'0')-1]+(leaveBob[3]-'0')*10+(leaveBob[4]-'0');
        int start = max(alice_start,Bob_start);
        int end = min(alice_end,Bob_end);
        int ans = end-start+1;
        return ans < 0 ? 0:ans;
    }
};