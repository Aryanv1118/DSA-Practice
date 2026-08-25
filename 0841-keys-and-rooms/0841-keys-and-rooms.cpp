class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>open(n,false);
        queue<int>q;
        q.push(0);
        open[0] = true;
        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(int r:rooms[room]){
                if(open[r])
                    continue;
                q.push(r);
                open[r] = true;
            }
        }
        for(int i = 0;i<n;i++){
            if(!open[i]){
                return false;
            }
        }
        return true;
    }
};