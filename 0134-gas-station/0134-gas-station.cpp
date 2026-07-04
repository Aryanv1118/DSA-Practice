class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0;
        int totalcost = 0;
        int n = gas.size();
        int tank = 0;
        int start = 0;
        for(int i = 0;i<n;i++){
            totalgas += gas[i];
            totalcost += cost[i];
        }
        if(totalcost>totalgas){
            return -1;
        }
        else{
            for(int i = 0;i<n;i++){
                tank = tank + (gas[i]-cost[i]);
                if(tank<0){
                    tank = 0;
                    start = i+1;
                }
            }
        }
        return start;
    }
};